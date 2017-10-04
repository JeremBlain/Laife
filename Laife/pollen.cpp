#include "pollen.h"

Pollen::Pollen()
{

}

Pollen::Pollen(int init_x, int init_y, int direction_x, int direction_y) : x(init_x), y(init_y), dir_x(direction_x), dir_y(direction_y)
{}

Pollen::~Pollen()
{
    delete this;
}

void Pollen::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::yellow);
    painter->setBrush(brush);
    painter->drawEllipse(x-Constant::POLLEN_SIZE/2,y-Constant::POLLEN_SIZE/2, Constant::POLLEN_SIZE,Constant::POLLEN_SIZE);
}

void Pollen::move()
{
    x += dir_x;
    y += dir_y;
}
