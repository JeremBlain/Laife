#include "animal_specie.hpp"

animal_specie::animal_specie() : Specie(50, 60)
{

}

animal_specie::animal_specie(int pos_x, int pos_y) : Specie(pos_x, pos_y)
{

}

void animal_specie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::red);
    painter->setBrush(brush);

    painter->drawEllipse(x-25,y-25, 50,50);
}
