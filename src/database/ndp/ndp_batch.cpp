//
// Created by giacomo on 07/12/24.
//

#include <database/ndp/ndp_batch.h>


#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <iostream>
#include <unistd.h>

size_t serialize(int fd, const gsm_object& object) {
    ::capnp::MallocMessageBuilder message;
    GSMObject::Builder  builder = message.initRoot<GSMObject>();
    builder.setId(object.id);
    {
        auto xi = builder.initXi(object.xi.size());
        for (size_t i = 0, N = object.xi.size(); i<N; i++) {
            xi.set(i, object.xi.at(i));
        }
    }
    {
        auto ell = builder.initEll(object.ell.size());
        for (size_t i = 0, N = object.ell.size(); i<N; i++) {
            ell.set(i, object.ell.at(i));
        }
    }
    {
        auto scores = builder.initScores(object.scores.size());
        for (size_t i = 0, N = object.scores.size(); i<N; i++) {
            scores.set(i, object.scores.at(i));
        }
    }
    {
        auto pi = builder.initPi();
        auto actual_pi = pi.initEntries(object.content.size());
        size_t idx = 0;
        for (const auto& [k,v] : object.content) {
            actual_pi[idx].setKey(k);
            if (std::holds_alternative<std::string>(v)) {
                actual_pi[idx].initValue().initVal().setStr(std::get<std::string>(v));
            } else if (std::holds_alternative<double>(v)) {
                actual_pi[idx].initValue().initVal().setFlt(std::get<double>(v));
            }
//            else if (std::holds_alternative<bool>(v)) {
//                actual_pi[idx].initValue().initVal().setBol(std::get<bool>(v));
//            } else if (std::holds_alternative<int64_t >(v)) {
//                actual_pi[idx].initValue().initVal().setVal(std::get<int64_t>(v));
//            }
            idx++;
        }
    }
    {
        auto content = builder.initContent();
        auto actual_content = content.initEntries(object.phi.size());
        size_t i = 0;
        for (const auto& [k,v] : object.phi) {
            actual_content[i].setKey(k);
            auto ls = actual_content[i].initValue(v.size());
            size_t j = 0;
            for (const auto& x : v) {
                ls[j].setId(x.id);
                ls[j].setOrigEdgeId(x.orig_edge_id);
                auto scores = ls[j].initScores(1);
                for (size_t kidx = 0, M = 1; kidx<M; kidx++)
                    scores.set(kidx,x.score);
                auto pi = ls[j].initPi();
                auto actual_pi = pi.initEntries(x.property_values.size());
                size_t l = 0;
                for (const auto& [k2, v2]:x.property_values) {
                    actual_pi[l].setKey(k2);
                    if (std::holds_alternative<std::string>(v2)) {
                        actual_pi[l].initValue().initVal().setStr(std::get<std::string>(v2));
                    } else if (std::holds_alternative<double>(v2)) {
                        actual_pi[l].initValue().initVal().setFlt(std::get<double>(v2));
                    }
//                    else if (std::holds_alternative<bool>(v2)) {
//                        actual_pi[l].initValue().initVal().setBol(std::get<bool>(v2));
//                    } else if (std::holds_alternative<int64_t >(v2)) {
//                        actual_pi[l].initValue().initVal().setVal(std::get<int64_t>(v2));
//                    }
                    l++;
                }
                j++;
            }
            i++;
        }
    }

    off_t scur, send;
    scur = lseek (fd, 0, SEEK_CUR);

    writePackedMessageToFd(fd, message);
    auto words = messageToFlatArray(message);
    kj::ArrayPtr<kj::byte> bytes = words.asBytes();
    write(fd, bytes.begin(), bytes.size());
    fsync(fd);

//    scur = lseek (fd, 0, SEEK_CUR);
//    send = lseek (f, 0, SEEK_END);
//    lseek (fd, 0, SEEK_CUR);
//    lseek (f, scur, SEEK_START);
//    return send == send;

    return scur;
}

void readEntry(int fd,  gsm_object& result) {
    ::capnp::PackedFdMessageReader message(fd);
    GSMObject::Reader object = message.getRoot<GSMObject>();
    result.id = object.getId();

    result.scores.clear();
    if (object.hasScores()) {
        auto scores = object.getScores();
        result.scores.reserve(scores.size());
        for (double val : scores) {
            result.scores.emplace_back(val);
        }
    }

    result.ell.clear();
    if (object.hasEll()) {
        auto ell =object.getEll();
        result.ell.reserve(ell.size());
        for (const std::string x : ell) {
            result.ell.emplace_back(x);
        }
    }

    result.xi.clear();
    if (object.hasXi()) {
        auto xi =object.getXi();
        result.xi.reserve(xi.size());
        for (const std::string x : xi) {
            result.xi.emplace_back(x);
        }
    }


    result.content.clear();
    if (object.hasPi()) {
        auto p = object.getPi();
        if (p.hasEntries()) {
            auto pi = p.getEntries();
            result.content.reserve(pi.size());
            for (const auto& x : pi) {
                if (x.hasValue() && x.hasKey()) {
                    auto val = x.getValue().getVal();
                    if (val.isBol()) {
                        result.content[x.getKey()] = val.getBol() ? 1.0 : 0.0;
                    } else if (val.isFlt()) {
                        result.content[x.getKey()] = val.getFlt();
                    } else if (val.isStr()) {
                        result.content[x.getKey()] = val.getStr();
                    } else if (val.isVal()) {
                        result.content[x.getKey()] = (double)val.getVal();
                    }
                }
            }
        }
    }


    result.phi.clear();
    if (object.hasContent()) {
        auto gc = object.getContent();
        if (gc.hasEntries()) {
            auto phi = gc.getEntries();
            result.phi.reserve(phi.size());
            for (const auto& y : phi) {
                if (y.hasKey() && y.hasValue()) {
                    auto& vectors = result.phi[y.getKey()];
                    for (const auto& x : y.getValue()) {
                        auto& loc = vectors.emplace_back();
                        loc.id = x.getId();
                        loc.orig_edge_id = x.getOrigEdgeId();

                        loc.score; //.clear();
                        if (x.hasScores()) {
                            auto scores2 = x.getScores();
//                            loc.score.reserve(scores2.size());

                            for (double val : scores2)
                                loc.score = (val);
                        }

                        loc.property_values.clear();
                        if (x.hasPi()) {
                            auto final = x.getPi();
                            if (final.hasEntries()) {
                                auto e = final.getEntries();
                                loc.property_values; //.reserve(e.size());
                                for (const auto& obj : e) {
                                    if (obj.hasKey() && obj.hasValue()) {
                                        auto val = obj.getValue().getVal();
                                        if (val.isBol()) {
                                            loc.property_values[obj.getKey()] = val.getBol() ? 1.0 : 0.0;
                                        } else if (val.isFlt()) {
                                            loc.property_values[obj.getKey()] = val.getFlt();
                                        } else if (val.isStr()) {
                                            loc.property_values[obj.getKey()] = val.getStr();
                                        } else if (val.isVal()) {
                                            loc.property_values[obj.getKey()] = (double)val.getVal();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

mapping::mapping(const std::string& filename, size_t cache_size) : cache(cache_size), filename{filename}, moved_for_read{false}  {
    size_t tmpsize = 0;
    if (std::filesystem::exists(filename)) {
        std::ifstream infile(filename+"_map.tab");
        std::string line;
        while (std::getline(infile, line))
        {
            std::stringstream ss;
            ss.str(line);
            std::string item;
            size_t key, value;
            if (std::getline(ss, item, '\t')) {
                sscanf(item.c_str(), "%zu", &key);
                greatestObjectId = std::max((ssize_t)key, greatestObjectId);
                if (std::getline(ss, item)) {
                    sscanf(item.c_str(), "%zu", &value);
                    metObjectIds.emplace(key, value);
                }
            }
            tmpsize = filesize(filename);

        }
    }
    fd=open(filename.c_str(), O_CREAT|O_RDWR|O_TRUNC, 0600);
    if (tmpsize>0)
        lseek(fd, tmpsize, SEEK_SET);
    empty_object.id = -1;
    empty_object.scores.emplace_back(-1);
    mapping_file.open(filename+"_map.tab");
}


std::pair<bool,size_t> mapping::serialize(const gsm_object& object) {
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    if (!metObjectIds.contains(object.id)) {
        cache.put(object.id, object);
        if (moved_for_read) {
            lseek(fd, 0, SEEK_END);
            moved_for_read = false;
        }
        size_t offset = ::serialize(fd, object);
        metObjectIds.emplace(object.id, offset);
        mapping_file << object.id << '\t' << offset << std::endl;
        return {true, offset};
    } else {
        return {false, 0};
    }
}

gsm_object mapping::retrieve(size_t id) {
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    auto it = metObjectIds.find(id);
    if (it == metObjectIds.end()) {
        return empty_object;
    } else {
        if (cache.exists(id) || (fd == -1)) {
            return cache.get(id);
        } else if (fd != -1) {
            moved_for_read = true;
            lseek(fd, it->second, SEEK_SET);
            gsm_object result;
            readEntry(fd, result);
            return result;
        } else {
            return empty_object;
        }
    }
}

void mapping::close() {
    ::close(fd);
    mapping_file.close();
    fd = -1;
}