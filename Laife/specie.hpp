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
    void move(int dx, int dy);
    virtual void change_behavior() = 0;

protected :
    int x, y; //coords
    Action action_state;

};

#endif // SPECIE_HPP
