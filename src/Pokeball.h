#pragma once
#include "Pokemon.h"
// A ball where a Pokemon sleeps.
class Pokeball
{
public:

    bool empty() const{
        return _empty;
    }

    void store(const Pokemon pokemon){
        _pokemon = pokemon;
        _empty = false;
    }

    void store(const PokemonPtr pokemon){
        _pokemon = *pokemon;
        _empty = false;
    }

    Pokemon pokemon() const{
        return _pokemon;
    }

private:
    bool _empty = true;
    Pokemon _pokemon;
};
