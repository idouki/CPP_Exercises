#pragma once

#include <string>
#include <memory>

// A creature that is cute and can fight other ones.
class Pokemon
{

public:
    Pokemon(const std::string name):
    _name {name},
    _id {count++}
    {}

    Pokemon(const Pokemon& other):
        _name {other._name},
        _id {count++}
    {}

    Pokemon() = default;

    std::string name() const{
        return _name;
    }

    int id() const {
        return _id;
    }

    Pokemon& operator=(const Pokemon& other){

       if(this != &other){
            _name = other._name;
        }

        return *this;
    }

private:
    std::string _name;    
    int _id;
    inline static int count = 1;
};

using PokemonPtr = std::unique_ptr<Pokemon>;
