#include "gamestate.hpp"

GameState::GameState()
{}


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
        specie->move(3,3);
    }
}

void GameState::change_behavior()
{
    for(auto &specie : species_array)
    {
        specie->change_behavior();
    }
}

void GameState::fill_up_cos_sin_array()
{
    for(int i=0; i<32; i++)
    {
        COS[i] = cos(3.14f*i/32);
        SIN[i] = sin(-1.67f + 3.14f*i/32);
    }
}

void GameState::display_cos_sin()
{
    for(int i=0; i<32; i++)
    {
        std::cout<<"Cos("<<i<<") = "<<COS[i]<<" ; Sin("<<i<<") = "<<SIN[i]<<std::endl;
    }
}

