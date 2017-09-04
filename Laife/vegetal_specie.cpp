#include "vegetal_specie.hpp"

vegetal_specie::vegetal_specie() : Specie(150, 170)
{

}

vegetal_specie::vegetal_specie(int pos_x, int pos_y) : Specie(pos_x, pos_y)
{

}


void vegetal_specie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::green);
    painter->setBrush(brush);

    painter->drawEllipse(x-25,y-25, 50,50);
}

void vegetal_specie::change_behavior()
{
    //do nothing for the moment
}
