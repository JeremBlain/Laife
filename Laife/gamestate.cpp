#include "gamestate.hpp"

GameState::GameState()
{}


void GameState::move()
{
    for(auto &specie : animals_array)
    {
        if(specie->get_action_state() == Action::Move)
            specie->move(3, COS);
    }
}

void GameState::find_partner()
{
    for(auto &specie : animals_array)
    {
        if(specie->get_action_state() == Action::Find_Partner)
            specie->find_partner(animals_array);
    }
}

void GameState::change_behavior()
{
    for(auto &specie : animals_array)
    {
        specie->change_behavior();
    }
    for(auto &specie : vegans_array)
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
    animals_array.push_back(new AnimalSpecie());
    animals_array.push_back(new AnimalSpecie(200, 220, Gender::Female) );
    vegans_array.push_back(new VegetableSpecie());
    vegans_array.push_back(new VegetableSpecie(333, 450, Gender::Female) );
}

void GameState::test_breed()
{
    std::cout<<"before breeding"<<std::endl;
    AnimalSpecie *new_born = animals_array[1]->breed(*animals_array[0]);
    std::cout<<"after breeding"<<std::endl;

    if(new_born == nullptr)
        std::cout<<"can't pushing, new_born is nullptr"<<std::endl;
    else
        animals_array.push_back(new_born);

    std::cout<<"after pushing"<<std::endl;

}
