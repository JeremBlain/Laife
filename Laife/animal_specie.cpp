#include "animal_specie.hpp"

animal_specie::animal_specie() : Specie(250, 60, 24),
                                 hunger(100),
                                 thirst(100),
                                 hapiness(100),
                                 tiredness(100)
{

}

animal_specie::animal_specie(int pos_x, int pos_y) : Specie(pos_x, pos_y, 24),
                                                     hunger(100), thirst(100), hapiness(100), tiredness(100)
{

}

void animal_specie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::red);
    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
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
