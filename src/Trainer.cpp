#include "Trainer.h"

void Trainer::capture(PokemonPtr pokemon)
{
    if (pokemon == nullptr)
    {
        return;
    }

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
