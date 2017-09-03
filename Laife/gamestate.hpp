#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <QTimer>

#include "animal_specie.hpp"
#include "vegetal_specie.hpp"

class GameState
{
public:
    GameState();

    std::vector<Specie*> species_array;

    /** This function has test purpose. Only for testing some parameters and functions */
    void create_test_game();
    void move();
    void change_behavior();
    void fill_up_cos_sin_array();

    //this function has only a test purpose, to see if the value of cos and sin are coherent
    void display_cos_sin();

    //array for storing cos() and sin() value
    float COS[33];
    float SIN[33];
};

#endif // GAMESTATE_HPP
