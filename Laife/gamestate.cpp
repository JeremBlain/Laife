#include "gamestate.hpp"

GameState::GameState()
{}


void GameState::move()
{
    for(auto &specie : animals_array)
    {
        if(specie->get_action_state() == Action::Move)
        {
            if(collision(specie) == false)
                specie->move( Constant::SPEED );
        }
    }

    if(!pollens_array.empty())
        for(auto &pollen : pollens_array)
        {
            pollen.move();
        }
}

bool GameState::collision(AnimalSpecie* animal)
{
    for(auto &species : animals_array)
    {
        if(animal->collision(QRect( species->get_x()-species->get_height()/2.0, species->get_y()-species->get_height()/2.0, species->get_height(), species->get_height() ),
                             species->get_number()))
        {
            return true;
        }
    }

    for(auto &species : vegans_array)
    {
        if(animal->collision(QRect( species->get_x()-species->get_height()/2.0, species->get_y()-species->get_height()/2.0, species->get_height(), species->get_height() ),
                              species->get_number()))
            return true;
    }

    return false;
}

bool GameState::collision(QRect hitbox)
{
    for(auto &species : animals_array)
    {
        QRect obj_box(species->get_x()-species->get_height()/2, species->get_y()-species->get_height()/2, species->get_height(), species->get_height());

        if(hitbox.intersects(obj_box) == true)
            return true;
    }

    for(auto &species : vegans_array)
    {
        QRect obj_box(species->get_x()-species->get_height()/2, species->get_y()-species->get_height()/2, species->get_height(), species->get_height());

        if(hitbox.intersects(obj_box) == true)
            return true;
    }

    return false; //no collision
}

bool GameState::generate_position_new_born(Specie* mother, int &pos_x, int &pos_y)
{
    int rand_x = -1, rand_y = -1;
    int height = mother->get_height();
    int it = 0; //number of iteration, for avoiding infinite loop

    do //make a position for the new born
    {
        rand_x = generate_random_pos(80, 40, height), rand_y = generate_random_pos(80, 40, height/2);
        ++it;
    }while(collision(QRect(mother->get_x()+rand_x-height/2, mother->get_y()+rand_y-height/2, height, height)) && it < 15);

    if(it < 15) //if it == 15 so we get out of the while without having a valide position for the newx born, so we return false !
    {
        pos_x = mother->get_x()+rand_x;  pos_y = mother->get_y()+rand_y;
        return true;
    }
    else
        return false;
}

void GameState::find_partner()
{
    for(auto &specie : animals_array)
    {
        if(specie->get_action_state() == Action::Find_Partner)
            specie->find_partner(animals_array);
    }
}

void GameState::breeding()
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
                    breeding_animals(animals_array[i], animals_array[j]);
                }

                //if ith animal is the male and jth is female
                if( animals_array[i]->get_gender() == Gender::Male   && animals_array[i]->get_breedable() == 0
                &&  animals_array[j]->get_gender() == Gender::Female && animals_array[j]->get_breedable() == 0)
                {
                    breeding_animals(animals_array[j], animals_array[i]);
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

    //for each pollen, see if it is close to a female plant and make a new plant if true
    for(auto it = pollens_array.begin(); it < pollens_array.end(); ++it)
    {
        for(auto &specie : vegans_array)
        {
            if(specie->get_gender() == Gender::Female && it->is_hitting_plant(specie->get_x(), specie->get_y()) == true)
            {
                breeding_plants(specie);
                pollens_array.erase(it); //the pollen is destroy when it is used for breed
            }
        }

    }
}

void GameState::breeding_animals(AnimalSpecie* female, AnimalSpecie* male)
{
    male->copulate(); female->copulate();

    int pos_x = -1, pos_y = -1;
    bool valid_pos = generate_position_new_born(female, pos_x, pos_y);
    if(valid_pos == false) //false <=> not valide position for the new born, abord
        return; //if there is not place to go, abord

    AnimalSpecie *new_born = female->breed(animals_array.size()+vegans_array.size(), pos_x, pos_y);
    if(new_born != nullptr)
    {
        animals_array.push_back(new_born);
        male->change_behavior(); // the male have to change is state from breed to rest, the state of female is changed in the breed function
    }
}

void GameState::breeding_plants(PlantSpecie *female)
{
    int pos_x = -1, pos_y = -1;
    bool valid_pos = generate_position_new_born(female, pos_x, pos_y);
    if(valid_pos == false) //false <=> not valide position for the new born, abord
        return; //if there is not place to go, abord

    PlantSpecie* new_born = female->breed(animals_array.size()+vegans_array.size(), pos_x, pos_y);
    if(new_born != nullptr)
        vegans_array.push_back(new_born);
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

    animals_array.push_back(new AnimalSpecie(Test::animal_specie_x_1, Test::animal_specie_y_1, animals_array.size()+vegans_array.size(), Gender::Female) );
    animals_array.push_back(new AnimalSpecie(Test::animal_specie_x_2, Test::animal_specie_y_2, animals_array.size()+vegans_array.size(), Gender::Male) );
    animals_array.push_back(new AnimalSpecie(Test::animal_specie_x_3, Test::animal_specie_y_3, animals_array.size()+vegans_array.size(), Gender::Male) );
    vegans_array.push_back(new PlantSpecie(Test::plant_specie_x_1, Test::plant_specie_y_1, animals_array.size()+vegans_array.size(), Gender::Female) );
    vegans_array.push_back(new PlantSpecie(Test::plant_specie_x_2, Test::plant_specie_y_2, animals_array.size()+vegans_array.size(), Gender::Male) );
    vegans_array.push_back(new PlantSpecie(Test::plant_specie_x_3, Test::plant_specie_y_3, animals_array.size()+vegans_array.size(), Gender::Female) );
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

   /* for(auto &pollen : pollens_array)
    {
        delete pollen;
    }*/
    pollens_array.clear();//all the pointer are freed so we can clear the array without leaks
}

void GameState::test_breed() //used it after init_test_game !
{

    std::cout<<"before breeding animal"<<std::endl;
    AnimalSpecie *new_born_a = animals_array[0]->breed(animals_array.size()+vegans_array.size(), 700, 700); //the baby is sent to the coords (700,700)
    std::cout<<"after breeding animal"<<std::endl;

    if(new_born_a == nullptr)
        std::cout<<"can't pushing, new_born is nullptr"<<std::endl;
    else
        animals_array.push_back(new_born_a);

    std::cout<<"after pushing animal"<<std::endl;

    std::cout<<"before breeding plant"<<std::endl;
    PlantSpecie *new_born_v = vegans_array[0]->breed(animals_array.size()+vegans_array.size(), 800, 800); //the baby is sent to the coords (800,800)
    std::cout<<"after breeding plant"<<std::endl;

    if(new_born_v == nullptr)
        std::cout<<"can't pushing, new_born is nullptr"<<std::endl;
    else
        vegans_array.push_back(new_born_v);

    std::cout<<"after pushing plant"<<std::endl;
}

void GameState::test_collision()
{
    //empty vectors first
    clear_array();

    animals_array.push_back(new AnimalSpecie(Test::collisiontest_1_x, Test::collisiontest_1_y, animals_array.size()+vegans_array.size(), Gender::Male) );
    animals_array.push_back(new AnimalSpecie(Test::collisiontest_2_x, Test::collisiontest_2_y, animals_array.size()+vegans_array.size(), Gender::Female) );
    animals_array.push_back(new AnimalSpecie(Test::collisiontest_3_x, Test::collisiontest_3_y, animals_array.size()+vegans_array.size(), Gender::Female) );
    animals_array.push_back(new AnimalSpecie(Test::collisiontest_4_x, Test::collisiontest_4_y, animals_array.size()+vegans_array.size(), Gender::Female) );
    vegans_array.push_back(new PlantSpecie(Test::collisiontest_5_x, Test::collisiontest_5_y, animals_array.size()+vegans_array.size(), Gender::Female) );
}
