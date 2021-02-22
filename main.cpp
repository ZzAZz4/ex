#include "include/LLParser.hpp"
#include <iostream>

auto addRule (Rules& rules, ID lhs, Rule rhs)
{
    rules.emplace(lhs, std::move(rhs));
}

int main ()
{
    Rules rules;
    constexpr ID start = "A";

    addRule(rules, "A", { "a", "a", "A" });
    addRule(rules, "A", { epsilon });

    LLParser parser (rules, start);
    std::string s;
    std::cout << "Input:\t";
    std::cin >> s;

    std::string_view result = parser.parse(s) ? "Accepted" : "Not accepted";
    std::cout << result << '\n';

    return 0;
}