#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "animal_specie.hpp"
#include "vegetal_specie.hpp"

class GameState
{
public:
    GameState();

    std::vector<Specie*> species_array;

    /** This function has test purpose. Only for testing some parameters and functions */
    void create_test_game();
};

#endif // GAMESTATE_HPP
