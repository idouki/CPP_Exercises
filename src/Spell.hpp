#pragma once

#include <string>
#include <string_view>
#include "Card.hpp"

enum class SpellType {
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

std::string_view to_string(const SpellType spell_type){ // TODO : pourquoi const

    switch(spell_type){
        case SpellType::Normal : return "Normal"; 
        case SpellType::Equip : return "Equip"; 
        case SpellType::Continuous : return "Continuous"; 
        case SpellType::QuickPlay : return "QuickPlay"; 
        case SpellType::Field : return "Field"; 
    }

    return "";

}

class Spell : public Card {
public:
    Spell(std::string id, std::string name ,SpellType type):
        Card {id, CardType::Spell},
        _spell_type {type}
    {
        set_name(std::move(name));
    }

    SpellType get_spell_type() const { return _spell_type; }

private:
    SpellType _spell_type;
};