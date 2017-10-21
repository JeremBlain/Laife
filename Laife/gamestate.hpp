#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <QTimer>

#include "animal_specie.hpp"
#include "vegetal_specie.hpp"

class GameState
{
public:
    GameState();

    std::vector<AnimalSpecie*> animals_array;
    std::vector<VegetableSpecie*> vegans_array;
    std::vector<Pollen*> pollens_array;

    //all these methods check if the species have the correct behavior (ex : move() check if the behavior of species is Move)
    void move(); //move all the animals species
    void find_partner(); //try to find a partner for all the species
    void breed();
    void change_behavior();
    void grow_old(); //method to grow old species, like his age, his breedable state, etc...


    /** These functions have test purpose. Only for testing some parameters and functions */
    void create_test_game();
    void test_breed();
};

#endif // GAMESTATE_HPP
