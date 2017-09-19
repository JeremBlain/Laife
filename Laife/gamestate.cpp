#include "gamestate.hpp"

GameState::GameState()
{}


void GameState::move()
{
    for(auto &specie : species_array)
    {
        specie->move(3, COS);
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
    for(int i=0; i<=32; i++)
    {
        COS[i] = cos(Constant::PI*i/32);
    }
}


//TEST value of COS and SIN
void GameState::display_cos_sin()
{
    for(int i=0; i<=32; i++)
    {
        std::cout<<"Cos("<<i<<") = "<<COS[i]<<std::endl;
    }
}


void GameState::create_test_game()
{
    species_array.push_back(new AnimalSpecie());
    species_array.push_back(new AnimalSpecie(200, 220, Gender::Female) );
    species_array.push_back(new VegetableSpecie());
    species_array.push_back(new VegetableSpecie(333, 450, Gender::Female) );
}

void GameState::test_breed()
{

}
