#pragma once

#include <string>
#include <string_view>

enum class CardType {
    Monster, Spell, Trap
};

std::string_view to_string(const CardType card_type){ // TODO : pourquoi const

    switch(card_type){
        case CardType::Monster : return "Monster"; 
        case CardType::Spell : return "Spell"; 
        case CardType::Trap : return "Trap"; 
    }

    return "";

}

class Card {
public:
    Card(std::string_view id, CardType type):
        _id {id},
        _type {type}
    {}

    void set_name(std::string name){ _name = name; }
    const std::string& get_name() const { return _name; }

    void set_description(std::string description){ _description = description; }
    const std::string& get_description() const { return _description; }

    const std::string& get_id() const { return _id; }

    CardType get_type() const { return _type; }

private:
    std::string _id = 0;
    std::string _name;
    std::string _description;
    CardType _type;
};