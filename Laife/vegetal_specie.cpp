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

    int probability = rand() % 10; //range from 0 to 99

    if(action_state == Action::Rest && probability < 5 && probability > 1)
    {
        action_state = Action::Move;
        std::cout<<"Action changed to Move"<<std::endl;
    }

    if(action_state == Action::Move && probability == 1)
    {
        action_state = Action::Rest;
        std::cout<<"Action changed to Rest"<<std::endl;
    }
}
