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

void GameState::breed()
{
    for(unsigned int i = 0; i < animals_array.size(); ++i)
    {
        for(unsigned int j = i+1; j < animals_array.size(); ++j)
        {
            if( distance(animals_array[i]->get_x(), animals_array[i]->get_y(), animals_array[j]->get_x(), animals_array[j]->get_y()) < 30)
            {
                //if ith animal is the female and jth is male
                if( animals_array[i]->get_gender() == Gender::Female && animals_array[j]->get_gender() == Gender::Male)
                {
                    AnimalSpecie *new_born = animals_array[i]->breed(*animals_array[j]);
                    if(new_born != nullptr)
                        animals_array.push_back(new_born);
                }

                //if ith animal is the male and jth is female
                if( animals_array[i]->get_gender() == Gender::Male && animals_array[j]->get_gender() == Gender::Female)
                {
                    AnimalSpecie *new_born = animals_array[j]->breed(*animals_array[i]);
                    if(new_born != nullptr)
                        animals_array.push_back(new_born);
                }
            }
        }
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

void GameState::grow_old()
{
    for(auto &specie : animals_array)
    {
        specie->decrement_breedable();
    }
    for(auto &specie : vegans_array)
    {
        specie->decrement_breedable();
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
    animals_array.push_back(new AnimalSpecie(200, 100, Gender::Female) );
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
