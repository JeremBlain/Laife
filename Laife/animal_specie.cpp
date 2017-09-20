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
{
    delete this;
}

void AnimalSpecie::draw_sprite(QPainter *painter)
{
    QBrush brush(Qt::red);
    painter->setBrush(brush);

    painter->drawEllipse(x-height/2,y-height/2, height,height);
}

void AnimalSpecie::change_behavior()
{
    int probability = rand() % 10; //range from 0 to 9

    if(action_state == Action::Rest && probability < 5 && probability > 1)
    {
        action_state = Action::Move;
        pos_x_reach = x + rand()%100-50;
        pos_y_reach = y + rand()%100-50;
    }

    if(action_state == Action::Move && probability == 1)
        action_state = Action::Rest;
}

AnimalSpecie* AnimalSpecie::breed(Specie &male)
{

    std::cout<<"animal is gender "<<gender<<" and the other is gender "<<male.get_gender()<<std::endl;
    //this is the female which gives the birth and we need the other specie to be a male
    if(gender == Gender::Female && male.get_gender() == Gender::Male)
    {
        AnimalSpecie* new_born = new AnimalSpecie(x+25, y+25, Gender::Male);
        return new_born;
    }

    return nullptr;
}

void AnimalSpecie::find_partner(std::vector<AnimalSpecie *> animals_array)
{
    for(auto &animal : animals_array)
    {
        int partner_x = animal->get_x();
        int partner_y = animal->get_y();

        int dist = distance(partner_x, partner_y, x, y);

        if(dist < 200)
        {

        }
    }
}
