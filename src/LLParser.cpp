#ifndef AA_LL_PARSER_IMPL
#define AA_LL_PARSER_IMPL

#include "../include/LLParser.hpp"

LLParser::LLParser (const Rules& rules, ID start) : start(start)
{
    for (auto[lhs, _] : rules)
        nonTerms.emplace(lhs);

    auto first = makeFirst(rules, nonTerms);
    auto follow = makeFollow(rules, start, first, nonTerms);
    table = makePredictors(rules, { first, follow, nonTerms });
}

bool LLParser::parse (std::string_view s)
{
    using Stack = std::vector<ID>;

    Stack stack;
    stack.emplace_back(endMark);
    stack.emplace_back(start);
    auto ip = 0;

    constexpr auto removeEps = [] (auto i) { return i != epsilon; };
    auto toStack = std::back_inserter(stack);

    while (stack.back() != endMark)
    {
        const auto& x = stack.back();
        auto prevA = s.substr(ip, x.size());
        auto a = prevA.empty() ? endMark : prevA;

        if (x == a)
        {
            stack.pop_back();
            ip += x.size();
        }

        else if (!contains(nonTerms, x))
            return false;

        else if (!contains(table, x) || !contains(table[x], a))
            return false;

        else
        {
            const Rule& rule = table[x].find(a)->second;
            stack.pop_back();
            std::copy_if(rule.rbegin(), rule.rend(), toStack, removeEps);
        }
    }
    return true;
}


#endif