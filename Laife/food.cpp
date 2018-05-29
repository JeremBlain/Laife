#include "food.hpp"

Food::Food()
{

}

void Food::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::blue);
    painter->setBrush(brush);
    painter->drawEllipse(x-Constant::FOOD_SIZE/2,y-Constant::FOOD_SIZE/2, Constant::FOOD_SIZE,Constant::FOOD_SIZE);
}
