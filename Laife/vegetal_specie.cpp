#include "vegetal_specie.hpp"

vegetal_specie::vegetal_specie() : Specie(150, 170, 30)
{

}

vegetal_specie::vegetal_specie(int pos_x, int pos_y) : Specie(pos_x, pos_y, 30)
{

}


void vegetal_specie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::green);
    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
}

void vegetal_specie::change_behavior()
{
    //do nothing for the moment
}

void vegetal_specie::breed(Specie male)
{

}
