#pragma once

#include <string>

enum CardType {
    Monster, Spell, Trap
};

std::string to_string(CardType card_type){
    auto result = std::string {};

    switch(card_type){
        case Monster : result = "Monster"; break;
        case Spell : result = "Spell"; break;
        case Trap : result = "Trap"; break;
    }

    return result;
}

class Card {
public:
    Card(std::string id, CardType type):
        _id {id},
        _type {type}
    {}

    void set_name(std::string name){ _name = name; }

    std::string get_name() const { return _name; }

    void set_description(std::string description){ _description = description; }

    std::string get_description() const { return _description; }

    std::string get_id() const { return _id; }

    CardType get_type() const { return _type; }

private:
    std::string _id = 0;
    std::string _name;
    std::string _description;
    CardType _type;
};