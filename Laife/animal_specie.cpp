#include "animal_specie.hpp"

animal_specie::animal_specie() : Specie(250, 60)
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

void animal_specie::change_behavior()
{
    int probability = rand() % 10; //range from 0 to 99

    if(action_state == Action::Rest && probability < 5 && probability > 1)
    {
        action_state = Action::Move;
        direction_angle = (rand()%180)/180.0f*2*Constant::PI;
    }

    if(action_state == Action::Move && probability == 1)
        action_state = Action::Rest;
}
