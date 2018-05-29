#include "food.hpp"

Food::Food()
{

}

Food::Food(int pos_x, int pos_y) : x(pos_x), y(pos_y) {}

Food::~Food()
{}

void Food::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::blue);
    painter->setBrush(brush);
    painter->drawEllipse(x-Constant::FOOD_SIZE/2,y-Constant::FOOD_SIZE/2, Constant::FOOD_SIZE,Constant::FOOD_SIZE);
}
