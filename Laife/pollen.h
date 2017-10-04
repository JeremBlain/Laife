#ifndef POLLEN_H
#define POLLEN_H


#include <QPainter>
#include "enumerations.hpp"

class Pollen
{
public:
    Pollen();
    Pollen(int init_x, int init_y, int direction_x, int direction_y);
    ~Pollen();

    void draw_sprite(QPainter *painter);
    void move();


private:
    int x,y; //coordinates
    int dir_x, dir_y; //direction to move
};

#endif // POLLEN_H
