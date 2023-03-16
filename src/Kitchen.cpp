#include "Kitchen.hpp"
#include "../lib/Unit.hpp"

#include <algorithm>
#include <string>
#include <memory>

const Unit& Kitchen::register_unit(Unit unit){
    auto res = _units.emplace(std::move(unit));
    return *(res.first);
}

const Unit* Kitchen::find_unit(const std::string& unit_name) const{
    auto it = std::find_if(_units.begin(), _units.end(), [unit_name](auto unit) {return unit_name == unit.name; });
    
    if(it == _units.end()){
        return nullptr;
    }

    return &(*it);
}

bool operator<(const Unit& a, const Unit& b)
{
    return a.name < b.name;
}

const Ingredient& Kitchen::register_ingredient(Ingredient ingredient){
    auto res = _ingredients.emplace(std::move(ingredient));
    return *(res.first);
}

bool case_insensitive_compare(const std::string &a, const std::string &b)  {
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [](char x, char y) {return std::tolower(x) == std::tolower(y);});
}

const Ingredient* Kitchen::find_ingredient(const std::string& ingredient_name) const{
    auto it = std::find_if(_ingredients.begin(), _ingredients.end(), [ingredient_name](auto ingredient) {return case_insensitive_compare(ingredient_name, ingredient.name); });
    
    if(it == _ingredients.end()){
        return nullptr;
    }

    return &(*it);
}




