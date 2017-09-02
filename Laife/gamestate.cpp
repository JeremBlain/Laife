#include "gamestate.hpp"

GameState::GameState()
{

}


void GameState::create_test_game()
{
    species_array.push_back(new animal_specie());
    species_array.push_back(new vegetal_specie());
    species_array.push_back(new animal_specie(200, 220) );
    species_array.push_back(new vegetal_specie(333, 450) );
}

void GameState::move()
{
    for(auto &specie : species_array)
    {
        specie->move(5,5);
    }
}
