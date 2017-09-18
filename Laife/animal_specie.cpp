#include "animal_specie.hpp"

AnimalSpecie::AnimalSpecie() : Specie(250, 60, 24),
                                 hunger(100),
                                 thirst(100),
                                 hapiness(100),
                                 tiredness(100)
{

}

AnimalSpecie::AnimalSpecie(int pos_x, int pos_y) : Specie(pos_x, pos_y, 24),
                                                     hunger(100), thirst(100), hapiness(100), tiredness(100)
{

}

void AnimalSpecie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::red);
    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
}

void AnimalSpecie::change_behavior()
{
    int probability = rand() % 10; //range from 0 to 99

    if(action_state == Action::Rest && probability < 5 && probability > 1)
    {
        action_state = Action::Move;
        direction_angle = rand()*2*Constant::PI;
    }

    if(action_state == Action::Move && probability == 1)
        action_state = Action::Rest;
}

Specie* AnimalSpecie::breed(Specie &male)
{
    //this is the female which gives the birth and we need the other specie to be a male
    if(gender == Gender::Female && male.get_gender() == Gender::Male)
    {
        AnimalSpecie* new_born = new AnimalSpecie(x+15, y+15);
        return new_born;
    }

    return nullptr;
}
