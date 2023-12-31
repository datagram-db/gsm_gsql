//
// Created by giacomo on 12/08/23.
//

#include "result.h"

bool result::operator<(const result &rhs) const {
    if (graphid < rhs.graphid)
        return true;
    if (rhs.graphid < graphid)
        return false;
        if (eventid < rhs.eventid)
        return true;
    if (rhs.eventid < eventid)
        return false;
    return globalEdgeId < rhs.globalEdgeId;
}

bool result::operator>(const result &rhs) const {
    return rhs < *this;
}

bool result::operator<=(const result &rhs) const {
    return !(rhs < *this);
}

bool result::operator>=(const result &rhs) const {
    return !(*this < rhs);
}

bool result::operator==(const result &rhs) const {
    return graphid == rhs.graphid &&
           eventid == rhs.eventid &&
           globalEdgeId == rhs.globalEdgeId;
}

bool result::operator!=(const result &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const result &result) {
    os << "{graph=" << result.graphid << ", event=" << result.eventid << ", edgeId=" << result.globalEdgeId <<"}";
    return os;
}
