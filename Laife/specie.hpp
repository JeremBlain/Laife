#ifndef SPECIE_HPP
#define SPECIE_HPP

#include <QPainter>
#include "enumerations.hpp"
#include "iostream"

class Specie
{
public:
    Specie();
    Specie(int pos_x, int pos_y);

    virtual void draw_sprite(QPainter *painter) = 0;
    void move(int dv, float COS[], float SIN[]);
    virtual void change_behavior() = 0;

protected :
    int x, y; //coords
    Action action_state;
    float direction_angle; //direction to move in radian

};

#endif // SPECIE_HPP
