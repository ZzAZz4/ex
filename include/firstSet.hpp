#ifndef AA_FIRST_SET_HPP
#define AA_FIRST_SET_HPP

#include "commons.hpp"

IDSet
rhsFirst (IDIter begin, IDIter end, SetMap& first, const IDSet& nonTerms);

SetMap
makeFirst (const Rules& rules, const IDSet& nonTerms);


#endif //AA_FIRST_SET_HPP
