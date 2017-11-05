#include "plant_specie.hpp"

//should never be used
PlantSpecie::PlantSpecie() : Specie()
{

}

PlantSpecie::PlantSpecie(int pos_x, int pos_y, int n, Gender g) : Specie(pos_x, pos_y, n, 30, g)
{

}

PlantSpecie::~PlantSpecie()
{}


void PlantSpecie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::darkGreen);
    if(gender == Gender::Female) //if female, change the color to green
        brush.setColor(Qt::green);

    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
}


void PlantSpecie::change_behavior()
{
    //have to be changed when breeding work !
    action_state = Action::Breed;
}


PlantSpecie* PlantSpecie::breed(int num_species, int pos_x, int pos_y)
{
    //this is the female which gives the birth and we need the other specie to be a male
    if(breedable == 0)
    {
        PlantSpecie* new_born;
        int proba_M_F = rand()%2;

        //generate a x and y between -20 and 20 for the new_born (we don't want to be on the mother so x and y must be superior than |height/2|
        //int rand_x = generate_random_pos(40, 20, height/2), rand_y = generate_random_pos(40, 20, height/2);

        if(proba_M_F == 0)
            new_born = new PlantSpecie(pos_x, pos_y, num_species, Gender::Male);
        else
            new_born = new PlantSpecie(pos_x, pos_y, num_species, Gender::Female);

        breedable = Constant::BREEDED;
        action_state = Action::Rest;
        return new_born;
    }

    return nullptr;
}

Pollen PlantSpecie::send_pollen()
{
    breedable = Constant::BREEDED;
    int rand_x = generate_random_pos(30, 15, 0), rand_y = generate_random_pos(30, 15, 0);

    //dir is for the direction of movement
    int dir_x = generate_random_pos(6, 3, 0), dir_y = generate_random_pos(6, 3, 0);
     //regenerate the direction until the pollen move !
    while(dir_x == 0 && dir_y == 0)
    {
        dir_x = generate_random_pos(6, 3, 0);
        dir_y = generate_random_pos(6, 3, 0);
    }

    return Pollen(x+rand_x, y+rand_y, dir_x, dir_y);
}


void PlantSpecie::copulate()
{
    if(action_state != Action::Breed)
    {
        action_state = Action::Breed;
        breedable = Constant::COPULATE; //just to don't make the breed instant
    }
}
