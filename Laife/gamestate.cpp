#include "gamestate.hpp"

GameState::GameState()
{}


void GameState::move()
{
    for(auto &specie : animals_array)
    {
        if(specie->get_action_state() == Action::Move)
            specie->move(3);
    }

    if(!pollens_array.empty())
        for(auto &pollen : pollens_array)
        {
            pollen->move();
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
            if( distance(animals_array[i]->get_x(), animals_array[i]->get_y(), animals_array[j]->get_x(), animals_array[j]->get_y()) < Constant::DISTANCE_MAX_BREED)
            {
                //if ith animal is the female and jth is male
                if( animals_array[i]->get_gender() == Gender::Female && animals_array[i]->get_breedable() == 0
                &&  animals_array[j]->get_gender() == Gender::Male   && animals_array[j]->get_breedable() == 0)
                {
                    animals_array[i]->copulate(); animals_array[j]->copulate();
                    AnimalSpecie *new_born = animals_array[i]->breed();
                    if(new_born != nullptr)
                    {
                        animals_array.push_back(new_born);
                        animals_array[j]->change_behavior(); // the male have to chnage is state from breed to rest, the state of female is changed in the breed function
                    }

                }

                //if ith animal is the male and jth is female
                if( animals_array[i]->get_gender() == Gender::Male   && animals_array[i]->get_breedable() == 0
                &&  animals_array[j]->get_gender() == Gender::Female && animals_array[j]->get_breedable() == 0)
                {
                    animals_array[i]->copulate(); animals_array[j]->copulate();
                    AnimalSpecie *new_born = animals_array[j]->breed();
                    if(new_born != nullptr)
                    {
                        animals_array.push_back(new_born);
                        animals_array[i]->change_behavior(); // the male have to chnage is state from breed to rest, the state of female is changed in the breed function
                    }
                }
            }
        }
    }

    for(auto &specie : vegans_array)
    {
        if(specie->get_gender() == Gender::Male && specie->get_breedable() == 0)
            pollens_array.push_back(specie->send_pollen());
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


void GameState::create_test_game()
{
    animals_array.push_back(new AnimalSpecie());
    animals_array.push_back(new AnimalSpecie(Test::first_animal_specie_x, Test::first_animal_specie_y, Gender::Female) );
    vegans_array.push_back(new VegetableSpecie());
    vegans_array.push_back(new VegetableSpecie(Test::first_vegetable_specie_x, Test::first_vegetable_specie_y, Gender::Female) );
}

void GameState::test_breed()
{
    std::cout<<"before breeding"<<std::endl;
    AnimalSpecie *new_born = animals_array[1]->breed();
    std::cout<<"after breeding"<<std::endl;

    if(new_born == nullptr)
        std::cout<<"can't pushing, new_born is nullptr"<<std::endl;
    else
        animals_array.push_back(new_born);

    std::cout<<"after pushing"<<std::endl;

}
