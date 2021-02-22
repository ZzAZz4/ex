#ifndef AA_COMMONS_HPP
#define AA_COMMONS_HPP

#include <vector>
#include <string_view>
#include <unordered_set>
#include <unordered_map>


using ID = std::string_view;
using Rule = std::vector<ID>;
using Rules = std::unordered_multimap<ID, Rule>;
using IDSet = std::unordered_set<ID>;
using SetMap = std::unordered_map<ID, IDSet>;
using IDIter = Rule::const_iterator;
using PTable = std::unordered_map<ID, std::unordered_multimap<ID, const Rule&>>;

struct FSets
{
    SetMap& first;
    SetMap& follow;
    IDSet& nonTerms;
};

constexpr ID epsilon = "";
constexpr ID endMark = "$";

template<template<class, class...> class Container, class T, class ... U>
bool contains (const Container<T, U...>& c, const T& elem);

#include "../src/commons.cpp"


#endif //AA_COMMONS_HPP
