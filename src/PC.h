#pragma once

#include "Pokemon.h"
#include "vector"

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    bool empty() const {
        return _pokemons.empty();
    }

    std::vector<PokemonPtr>& pokemons() { // TODO : pourquoi ça ne marche pas avec const
        return _pokemons;
    }

    void transfer(PokemonPtr pokemon){
        if(pokemon != nullptr){
            _pokemons.push_back(std::move(pokemon));
        }
    }

private:
    std::vector<PokemonPtr> _pokemons;
};
