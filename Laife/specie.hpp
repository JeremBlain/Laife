#ifndef SPECIE_HPP
#define SPECIE_HPP

#include <QPainter>
#include "enumerations.hpp"
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

    void move(int dv, float COS[]);

    // GETTER & SETTER
    Gender get_gender();
    Action get_action_state();
    int get_x();
    int get_y();

protected :
    int x, y; //coords
    Action action_state; //Behavior of the specie
    float direction_angle; //direction to move in radian


    // Caracteristics :
    int weight;
    int height;
    Gender gender;
    int age;

};

#endif // SPECIE_HPP
