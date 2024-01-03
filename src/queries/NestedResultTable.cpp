//
// Created by giacomo on 02/01/24.
//

#include "queries/NestedResultTable.h"
#include "scriptv2/ScriptAST.h"

//bool NestedResultTable::operator==(const NestedResultTable &rhs) const {
//    return cell_nested_morphism == rhs.cell_nested_morphism &&
//           column == rhs.column &&
//           content == rhs.content &&
//           t == rhs.t &&
//           areIndicesIndicated == rhs.areIndicesIndicated &&
//           indices == rhs.indices;
//}
//
//bool NestedResultTable::operator!=(const NestedResultTable &rhs) const {
//    return !(rhs == *this);
//}
//
//bool NestedResultTable::operator<(const NestedResultTable &rhs) const {
//    if (cell_nested_morphism < rhs.cell_nested_morphism)
//        return true;
//    if (rhs.cell_nested_morphism < cell_nested_morphism)
//        return false;
//    if (column < rhs.column)
//        return true;
//    if (rhs.column < column)
//        return false;
//    if (content < rhs.content)
//        return true;
//    if (rhs.content < content)
//        return false;
//    if (t < rhs.t)
//        return true;
//    if (rhs.t < t)
//        return false;
//    if (areIndicesIndicated < rhs.areIndicesIndicated)
//        return true;
//    if (rhs.areIndicesIndicated < areIndicesIndicated)
//        return false;
//    return indices < rhs.indices;
//}
//
//bool NestedResultTable::operator>(const NestedResultTable &rhs) const {
//    return rhs < *this;
//}
//
//bool NestedResultTable::operator<=(const NestedResultTable &rhs) const {
//    return !(rhs < *this);
//}
//
//bool NestedResultTable::operator>=(const NestedResultTable &rhs) const {
//    return !(*this < rhs);
//}