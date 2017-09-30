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

    void move();
    void find_partner();
    void breed();
    void change_behavior();
    void grow_old(); //function to grow old species, like his age, his breedable state, etc...


    /** These functions have test purpose. Only for testing some parameters and functions */
    void create_test_game();
    void test_breed();
};

#endif // GAMESTATE_HPP
