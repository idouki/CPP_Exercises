#pragma once

#include <vector>
#include <algorithm>

#include "Pokemon.h"

class Pokedex
{
public:
    void add(const Pokemon &pokemon)
    {
        _pokemons.push_back(&pokemon);
    }

    std::vector<const Pokemon *> find(const std::string &pokemon_name) const
    {
        auto result = std::find_if(_pokemons.begin(), _pokemons.end(), [&pokemon_name](const auto &pokemon)
                                   { return pokemon->name() == pokemon_name; });

        auto pokemons = std::vector<const Pokemon *>{};

        while (result != _pokemons.end())
        {
            if ((*result)->name() == pokemon_name)
            {
                pokemons.push_back(*result);
            }
            result++;
        }

        return pokemons;
    }

private:
    std::vector<const Pokemon *> _pokemons; // PRK pas des unique_ptr
};
