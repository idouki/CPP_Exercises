#pragma once

#include <set>
#include <string>

#include "../lib/Unit.hpp"
#include "../lib/Ingredient.hpp"

class Kitchen
{
public:
    const Unit& register_unit(Unit unit);
    const Unit* find_unit(const std::string& unit_name) const;

    const Ingredient& register_ingredient(Ingredient unit);
    const Ingredient* find_ingredient(const std::string& unit_name) const;
    
private:
    std::set<Unit> _units;   
    std::set<Ingredient> _ingredients;  
};


