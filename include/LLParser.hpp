#ifndef AA_LL_PARSER_HPP
#define AA_LL_PARSER_HPP

#include "firstSet.hpp"
#include "followSet.hpp"
#include "predictorSet.hpp"

struct LLParser
{
    PTable table;
    IDSet nonTerms;
    ID start;

    explicit
    LLParser (const Rules& rules, ID start);

    bool
    parse (std::string_view s);
};


#endif //AA_LL_PARSER_HPP
