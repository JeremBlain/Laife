#ifndef SPECIE_HPP
#define SPECIE_HPP

#include <QPainter>

class Specie
{
public:
    Specie();
    Specie(int pos_x, int pos_y);

    virtual void draw_sprite(QPainter *painter) = 0;

protected :
    int x, y; //coords
};

#endif // SPECIE_HPP
