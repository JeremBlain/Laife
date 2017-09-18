#include "vegetal_specie.hpp"

VegetableSpecie::VegetableSpecie() : Specie(150, 170, 30)
{

}

VegetableSpecie::VegetableSpecie(int pos_x, int pos_y) : Specie(pos_x, pos_y, 30)
{

}


void VegetableSpecie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::green);
    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
}

void VegetableSpecie::change_behavior()
{
    //do nothing for the moment
}

Specie* VegetableSpecie::breed(Specie &male)
{

}
