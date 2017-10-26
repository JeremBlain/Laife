#include "vegetal_specie.hpp"

VegetableSpecie::VegetableSpecie() : Specie(150, 170, 30, Gender::Male)
{

}

VegetableSpecie::VegetableSpecie(int pos_x, int pos_y, Gender g) : Specie(pos_x, pos_y, 30, g)
{

}

VegetableSpecie::~VegetableSpecie()
{}


void VegetableSpecie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::darkGreen);
    if(gender == Gender::Female) //if female, change the color to green
        brush.setColor(Qt::green);

    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
}


void VegetableSpecie::change_behavior()
{
    //have to be changed when breeding work !
    action_state = Action::Breed;
}


VegetableSpecie* VegetableSpecie::breed()
{
    //this is the female which gives the birth and we need the other specie to be a male
    if(breedable == 0)
    {
        VegetableSpecie* new_born;
        int proba_M_F = rand()%2;
        if(proba_M_F == 0)
            new_born = new VegetableSpecie(x+25, y+25, Gender::Male);
        else
            new_born = new VegetableSpecie(x+25, y+25, Gender::Female);

        breedable = Constant::BREEDED;
        action_state = Action::Rest;
        return new_born;
    }

    return nullptr;
}

Pollen* VegetableSpecie::send_pollen()
{
    breedable = Constant::BREEDED;
    return new Pollen(x+15, y+15, 1, 0);
}


void VegetableSpecie::copulate()
{
    if(action_state != Action::Breed)
    {
        action_state = Action::Breed;
        breedable = Constant::COPULATE; //just to don't make the breed instant
    }
}
