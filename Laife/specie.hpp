#ifndef SPECIE_HPP
#define SPECIE_HPP

#include <QPainter>
#include "enumerations.hpp"
#include "general_functions.hpp"
#include "iostream"

class Specie
{
public:
    Specie();
    Specie(int pos_x, int pos_y, int h, Gender g);

    virtual ~Specie() = 0;

    virtual void draw_sprite(QPainter *painter) = 0;
    virtual void change_behavior() = 0;
    virtual Specie* breed(Specie &male) = 0;

    void move(int speed, float COS[]);
    void decrement_breedable();

    // GETTER & SETTER
    Gender get_gender();
    Action get_action_state();
    int get_x();
    int get_y();

protected :
    int x, y; //coords
    Action action_state; //Behavior of the specie
    int pos_x_reach; //coordinates the specie want to reach
    int pos_y_reach;


    // Caracteristics :
    int weight;
    int height;
    Gender gender;
    int age;
    int breedable;
};

#endif // SPECIE_HPP
