#include "Trainer.h"

void Trainer::capture(PokemonPtr pokemon)
{
    if (pokemon == nullptr)
    {
        return;
    }

    pokemon->set_trainer(*this);

    for (auto &pokeball : _pokeballs)
    {
        if (pokeball.empty())
        {
            pokeball.store(std::move(pokemon));
            return;
        }
    }

    _pc.transfer(std::move(pokemon));
}

void Trainer::store_in_pc(const int pokemon_id) // TODO : pourquoi size_t
{
    Pokeball &pokeball = _pokeballs[pokemon_id];
    _pc.transfer(std::move(pokeball.remove()));
}
