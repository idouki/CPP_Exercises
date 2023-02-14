#pragma once
#include "Pokemon.h"
// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const
    {
        return _pokemon == nullptr;
    }

    void store(PokemonPtr pokemon)
    {
        _pokemon = std::move(pokemon);
    }

    PokemonPtr remove()
    {
        return std::move(_pokemon);
    }

    Pokemon &pokemon() const
    {
        return *_pokemon;
    }

private:
    bool _empty = true;
    PokemonPtr _pokemon;
};
