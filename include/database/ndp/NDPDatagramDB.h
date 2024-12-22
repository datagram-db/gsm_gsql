//
// Created by giacomo on 08/12/24.
//

#ifndef GSM2_NDPDATAGRAMDB_H
#define GSM2_NDPDATAGRAMDB_H

#include <map>
#include <yaucl/data/FixedSizeNDPSorter.h>
#include <database/ActivityTable.h>
#include <yaucl/structures/any_to_uint_bimap.h>

struct NDPDatagramDBLoad {
    size_t nGraphs = 0;
    std::map<size_t, std::string> minRecordToContaimentLabel;
    FixedSizeReaderWriter<gsm2::tables::ActivityTable::record> main_registry;
    yaucl::structures::any_to_uint_bimap<std::string> label_map;
};

#endif //GSM2_NDPDATAGRAMDB_H
