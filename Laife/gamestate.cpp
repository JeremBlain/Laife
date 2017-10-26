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
    //for each couple of animals, see if they can breed (close, and breedable)
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
                        animals_array[j]->change_behavior(); // the male have to change is state from breed to rest, the state of female is changed in the breed function
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
                        animals_array[i]->change_behavior(); // the male have to change is state from breed to rest, the state of female is changed in the breed function
                    }
                }
            }
        }
    }


    //for each male veegtable, send pollen (if he can/want breed)
    for(auto &specie : vegans_array)
    {
        if(specie->get_gender() == Gender::Male && specie->get_breedable() == 0)
            pollens_array.push_back(specie->send_pollen());
    }

    //for each pollen, see if it is close to a female vegetable and make a new vegetable if true
    for(auto &pollen : pollens_array)
    {
        for(auto &specie : vegans_array)
        {
            if(specie->get_gender() == Gender::Female && pollen->is_hitting_vegetable(specie->get_x(), specie->get_y()) == true)
            {
                VegetableSpecie* new_born = specie->breed();
                if(new_born != nullptr)
                    vegans_array.push_back(new_born);
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


void GameState::init_test_game()
{
    //empty vectors first
    clear_array();

    animals_array.push_back(new AnimalSpecie());
    animals_array.push_back(new AnimalSpecie(Test::first_animal_specie_x, Test::first_animal_specie_y, Gender::Female) );
    vegans_array.push_back(new VegetableSpecie());
    vegans_array.push_back(new VegetableSpecie(Test::first_vegetable_specie_x, Test::first_vegetable_specie_y, Gender::Female) );
}

void GameState::clear_array()
{
    for(auto &species : animals_array)
    {
        delete species;
    }
    animals_array.clear(); //all the pointer are freed so wer can clear the array without leaks

    for(auto &species : vegans_array)
    {
        delete species;
    }
    vegans_array.clear();//all the pointer are freed so wer can clear the array without leaks

    for(auto &pollen : pollens_array)
    {
        delete pollen;
    }
    pollens_array.clear();//all the pointer are freed so wer can clear the array without leaks
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
