#include "vegetal_specie.hpp"

VegetableSpecie::VegetableSpecie() : Specie(150, 170, 30, Gender::Male)
{

}

VegetableSpecie::VegetableSpecie(int pos_x, int pos_y, Gender g) : Specie(pos_x, pos_y, 30, g)
{

}

VegetableSpecie::~VegetableSpecie()
{
    delete this;
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

VegetableSpecie* VegetableSpecie::breed(Specie &male)
{
    //this is the female which gives the birth and we need the other specie to be a male
    if(gender == Gender::Female && male.get_gender() == Gender::Male)
    {
        VegetableSpecie* new_born = new VegetableSpecie(x+25, y+25, Gender::Male);
        return new_born;
    }

    return nullptr;
}


void VegetableSpecie::copulate()
{
    if(action_state != Action::Breed)
    {
        action_state = Action::Breed;
        breedable = Constant::COPULATE; //just to don't make the breed instant
    }
}
