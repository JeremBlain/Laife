#ifndef FOOD_HPP
#define FOOD_HPP

#include <QPainter>
#include "enumerations.hpp"

class Food
{
public:
    Food();
    Food(int pos_x, int pos_y);
    ~Food();

    void draw_sprite(QPainter *painter);

private:
    int x,y; //positions
};

#endif // FOOD_HPP
