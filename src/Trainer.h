#pragma once

#include "PC.h"
#include "Pokeball.h"
#include <array>

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string name, PC &pc) : _name{name},
                                              _pc{pc}
    {
    }

    const std::string &name() const { return _name; }

    const std::array<Pokeball, 6> &pokeballs() const { return _pokeballs; } // TODO Pourquoi, il faut mettre const

    void capture(PokemonPtr pokemon);

    void store_in_pc(const int pokemon_id);

    void fetch_from_pc(const std::string &pokemon_name);

private:
    const std::string _name;
    PC &_pc;
    std::array<Pokeball, 6> _pokeballs;
    int pokemonCount = 0;
};
