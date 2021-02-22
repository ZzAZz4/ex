#ifndef AA_PREDICTOR_SET_IMPL
#define AA_PREDICTOR_SET_IMPL

#include "../include/predictorSet.hpp"
#include "../include/firstSet.hpp"

PTable makePredictors (const Rules& rules, FSets sets)
{
    PTable table;
    for (auto&[lhs, rhs] : rules)
    {
        auto& entry = table[lhs];
        auto begin = rhs.begin(), end = rhs.end();
        auto first = rhsFirst(begin, end, sets.first, sets.nonTerms);
        auto hasEpsilon = first.erase(epsilon);

        for (auto b : first)
            entry.emplace(b, rhs);

        if (hasEpsilon)
        {
            for (auto&& x : sets.follow.at(lhs))
                entry.emplace(x, rhs);
        }
    }

    return table;

}

#endif