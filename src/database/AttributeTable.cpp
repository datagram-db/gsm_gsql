//
// Created by giacomo on 28/05/23.
//

#include "database/AttributeTable.h"

namespace gsm2 {
    namespace tables {
        AttributeTable::record::record(size_t act, size_t value, size_t actTableOffset) : act(act), value(value),
                                                                                         act_table_offset(actTableOffset) {}

        union_type AttributeTable::resolve(const AttributeTable::record &x) const {
            switch (type) {
                case DoubleAtt:
                    return *(double*)(&x.value);
                case LongAtt:
                    return *(long long*)(&x.value);
                case StringAtt:
                    return ptr.get(x.value);
                case BoolAtt:
                    return x.value != 0;
                    //case SizeTAtt:
                default:
                    // TODO: hierarchical types!, https://dl.acm.org/doi/10.1145/3410566.3410583
                    return x.value;
            }
        }

        bool AttributeTable::assertVariant(const std::variant<double, size_t, long long int, std::string, bool> &val) {
            switch (type) {
                case DoubleAtt:
                    return std::holds_alternative<double>(val);
                case SizeTAtt:
                    return std::holds_alternative<size_t>(val);
                case LongAtt:
                    return std::holds_alternative<long long>(val);
                case StringAtt:
                    return std::holds_alternative<std::string>(val);
                case BoolAtt:
                    return std::holds_alternative<bool>(val);
                default:
                    return false;
            }
        }

        void
        AttributeTable::record_load(size_t act_id,
                                    const std::variant<double, size_t, long long int, std::string, bool> &val,
                                    size_t tid,
                                    size_t eid) {
//            DEBUG_ASSERT(assertVariant(val));
            while (elements.size() <= act_id)
                elements.emplace_back();
            elements[act_id][val].emplace_back(tid, eid);
        }


        void AttributeTable::index(const std::vector<std::vector<size_t>> &trace_id_to_event_id_to_offset) {
            for (size_t act_id = 0, N = elements.size(); act_id < N; act_id++) {
                auto& ref = elements[act_id];
                size_t begin = table.size();
                if (!ref.empty()) {
                    std::map<union_type, std::vector<size_t>> valueToOffsetInTable;
                    for (const auto& val_offset : ref) {
                        for (const auto& traceid_eventid : val_offset.second) {
                            size_t offset =
                                    trace_id_to_event_id_to_offset.at(traceid_eventid.first).at(traceid_eventid.second);

                            valueToOffsetInTable[val_offset.first].emplace_back(offset);
                        }
                    }
                    for (auto it = valueToOffsetInTable.begin(); it != valueToOffsetInTable.end(); it++) {
                        std::sort(it->second.begin(), it->second.end());
                        size_t val = storeLoad(it->first);
                        std::string current_string;
                        if (type == StringAtt)
                            current_string = std::get<std::string>(it->first);
                        for (const auto& refx : it->second) {
                            if (type == StringAtt)
                                string_offset_mapping[current_string].emplace_back(table.size());
                            secondary_index[refx] = table.size();
                            table.emplace_back(act_id, val, refx);
                        }
//                it = valueToOffsetInTable.erase(it);
                    }
                    valueToOffsetInTable.clear();
                    ref.clear();
                }
                size_t end = table.size();
                primary_index.emplace_back(begin, end);
            }
            elements.clear();
        }

        const AttributeTable::record * AttributeTable::resolve_record_if_exists(size_t actTableOffset) const {
            auto it = secondary_index.find(actTableOffset);
            if (it == secondary_index.end())
                return nullptr;
            else
                return (table.data()) + it->second;
        }

        std::ostream &AttributeTable::resolve_and_print(std::ostream &os, const AttributeTable::record &x) const {
            switch (type) {
                case DoubleAtt:
                    return os << *(double*)(&x.value);
                case LongAtt:
                    return os << *(long long*)(&x.value);
                case StringAtt:
                    return os << ptr.get(x.value);
                case BoolAtt:
                    return os << ((x.value != 0) ? "true" : "false");
                    //case SizeTAtt:
                default:
                    // TODO: hierarchical types!, https://dl.acm.org/doi/10.1145/3410566.3410583
                    return os << x.value;
            }
        }


        size_t AttributeTable::storeLoad(const std::variant<double, size_t, long long int, std::string, bool> &x) {
            switch (type) {
                case DoubleAtt: {
                    double tmp = std::get<double>(x);
                    return *(size_t*)(&tmp);
                }

                case LongAtt: {
                    long long tmp = std::get<long long>(x);
                    return *(size_t*)(&tmp);
                }

                case StringAtt: {
                    std::string tmp = std::get<std::string>(x);
                    return ptr.put(tmp).first;
                }
                case BoolAtt:
                    return std::get<bool>(x) ? 1 : 0;
                    //case SizeTAtt:
                default:
                    // TODO: hierarchical types!, https://dl.acm.org/doi/10.1145/3410566.3410583
                    return std::get<size_t>(x);
            }
        }

        union_minimal resolveUnionMinimal(const AttributeTable &table, const AttributeTable::record &x) {
            switch (table.type) {
                case DoubleAtt:
                    return *(double*)(&x.value);
                case LongAtt:
                    return (double)(*(long long*)(&x.value));
                case StringAtt:
                    return table.ptr.get(x.value);
                case BoolAtt:
                    return (x.value != 0 ? 0.0 : 1.0);
                    //case SizeTAtt:
                default:
                    // TODO: hierarchical types!, https://dl.acm.org/doi/10.1145/3410566.3410583
                    return (double)x.value;
            }
        }

        std::optional<union_minimal> AttributeTable::resolve_record_if_exists2(size_t actTableOffset) const {
            auto ptr = resolve_record_if_exists(actTableOffset);
            if (!ptr) return {};
            else return {resolveUnionMinimal(*this, *ptr)};
        }

        std::vector<std::vector<std::pair<const AttributeTable::record *, const AttributeTable::record *>>>
        AttributeTable::exact_range_query(
                const std::vector<std::pair<size_t, std::vector<DataQuery *>>> &propList) const {
            std::vector<std::vector<std::pair<const AttributeTable::record *, const AttributeTable::record *>>> finalResult;
            //std::pair<const AttributeTable::record *, const AttributeTable::record *> thisResult{nullptr, nullptr};
            for (const auto& cps : propList) {
                auto& actualResult = finalResult.emplace_back();
                size_t actId = cps.first;
                if ((actId > primary_index.size())) {
                    for (size_t i = 0, N = cps.second.size(); i<N; i++)
                        actualResult.emplace_back(nullptr, nullptr);
                }
                auto it = primary_index.at(actId);
                if (it.first == it.second) {
                    for (size_t i = 0, N = cps.second.size(); i<N; i++)
                        actualResult.emplace_back(nullptr, nullptr);
                } else {
                    DEBUG_ASSERT(table.size() >= it.first);
                    DEBUG_ASSERT(table.size() >= it.second);
                    const record* begin = table.data() + it.first;
                    const record* end = table.data() + it.second;

                    auto propRef = cps.second.begin(), propEnd = cps.second.end();
                    do {
                        const union_type prop_leftValue = cast_unions(type, (*propRef)->lower_bound);
                        const union_type prop_rightValue = cast_unions(type, (*propRef)->upper_bound);

                        const record* lb = std::lower_bound(begin, end, prop_leftValue, [&](const record &r, const union_type &value) {
                            return resolve(r) < value;
                        });

                        if (lb != end) {
                            const record* ub = std::upper_bound(begin, end, prop_rightValue, [&](const union_type &value, const record &r) {
                                return resolve(r) > value;
                            });

                            auto tmpLeft = lb;
                            auto tmpRight = ub;
                            if (tmpRight != end) {
                                tmpRight--;
                            }
                            else
                                tmpRight = table.data() + (it.second-1);

                            if (std::distance(tmpLeft, tmpRight) < 0) {
                                actualResult.emplace_back(nullptr, nullptr);
                            } else {
                                actualResult.emplace_back(tmpLeft, tmpRight);
                                begin = tmpRight;
                            }
                        } else {
                            actualResult.emplace_back(nullptr, nullptr);
                        }

                        propRef++;
                    } while (propRef != propEnd);
                }
            }
            return finalResult;
        }
    } // gsm2
} // tables