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
    void fill_up_cos_sin_array();
    void grow_old(); //function to grow old species, like his age, his breedable state, etc...

    //this function has only a test purpose, to see if the value of cos and sin are coherent
    void display_cos_sin();


    /** These functions have test purpose. Only for testing some parameters and functions */
    void create_test_game();
    void test_breed();

    //array for storing cos() and sin() value. Don't need to be private but don't change his values !
    float COS[33];
};

#endif // GAMESTATE_HPP
