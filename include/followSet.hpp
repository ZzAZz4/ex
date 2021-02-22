#ifndef AA_FOLLOW_SET_HPP
#define AA_FOLLOW_SET_HPP

#include "firstSet.hpp"
#include <algorithm>

IDIter
findProduction (IDIter begin, IDIter end, IDSet& nonTerms);

IDSet
rhsFollow (ID lhs, IDIter begin, IDIter end, FSets sets);

SetMap
makeFollow (const Rules& rules, ID start, SetMap& first, IDSet& nonTerms);

#endif //AA_FOLLOW_SET_HPP
