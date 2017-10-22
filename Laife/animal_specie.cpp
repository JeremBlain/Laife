#include "animal_specie.hpp"

AnimalSpecie::AnimalSpecie() : Specie(250, 60, 24, Gender::Male),
                                 hunger(100),
                                 thirst(100),
                                 hapiness(100),
                                 tiredness(100)
{

}

AnimalSpecie::AnimalSpecie(int pos_x, int pos_y, Gender g) : Specie(pos_x, pos_y, 24, g),
                                                     hunger(100), thirst(100), hapiness(100), tiredness(100)
{

}

AnimalSpecie::~AnimalSpecie()
{}

void AnimalSpecie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::red);
    if(gender == Gender::Female) //if female, change the color to magenta
        brush.setColor(Qt::magenta);

    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
}

void AnimalSpecie::change_behavior()
{
    // if action state is in Breed state and breedable is 0, then the breeding is finish and the action can be set to rest
    if(action_state == Action::Breed && breedable == 0)
    {
        action_state = Action::Rest;
    }

    if(action_state == Action::Rest)
    {
        int probability = rand() % 10; //range from 0 to 9

        if(probability >= 0 && probability < 4)
        {
            action_state = Action::Move;
            pos_x_reach = x + rand()%100-50;
            pos_y_reach = y + rand()%100-50;
        }

        if(probability >= 4 && probability < 6 && breedable == 0) //if the animal can't reproduce, doesn't need to find a partner
            action_state = Action::Find_Partner;
    }
}

AnimalSpecie* AnimalSpecie::breed()
{
    //this is the female which gives the birth and we need the other specie to be a male
    if(breedable == 0)
    {
        AnimalSpecie* new_born;
        int proba_M_F = rand()%2;
        if(proba_M_F == 0)
            new_born = new AnimalSpecie(x+25, y+25, Gender::Male);
        else
            new_born = new AnimalSpecie(x+25, y+25, Gender::Female);

        breedable = Constant::BREEDED;
        action_state = Action::Rest;
        return new_born;
    }

    return nullptr;
}

void AnimalSpecie::copulate()
{
    if(action_state != Action::Breed && breedable == 0)
    {
        action_state = Action::Breed;
        breedable = Constant::COPULATE; //just for don't making the breed instant
    }
}

void AnimalSpecie::find_partner(std::vector<AnimalSpecie *> &animals_array)
{
    for(auto &animal : animals_array)
    {
        int partner_x = animal->get_x();
        int partner_y = animal->get_y();

        int dist = distance(partner_x, partner_y, x, y);

        if(dist < Constant::DISTANCE_MIN_FIND_PARTNER)
        {
            pos_x_reach = partner_x;
            pos_y_reach = partner_y;

            action_state = Action::Move;
        }
    }
}
