#ifndef FOOD_HPP
#define FOOD_HPP

#include <QPainter>
#include "enumerations.hpp"

class Food
{
public:
    Food();
    void draw_sprite(QPainter *painter);

private:
    int x,y; //positions
};

#endif // FOOD_HPP
