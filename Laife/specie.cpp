#include "specie.hpp"

/** Abstract class for vegetals and animals species
 *
 * */

Specie::Specie() : x(100), y(100), action_state(Action::Rest), pos_x_reach(x), pos_y_reach(y),
                   weight(10), height(24), gender(Gender::Male), age(0), breedable(0)
{

}

Specie::Specie(int pos_x, int pos_y, int h, Gender g) : x(pos_x), y(pos_y), action_state(Action::Rest),
                                       weight(10), height(h), gender(g), age(0), breedable(0)
{
    //default : the specie will reach a point near it
    pos_x_reach = x + rand()%100-50;
    pos_y_reach = y + rand()%100-50;
}

Specie::~Specie()
{
}

void Specie::move(int speed, float COS[])
{
        //int i = direction_angle*32/(Constant::PI);

        float dist = distance(pos_x_reach, pos_y_reach, x, y); //float for keeping the float operations after with dx and dy !

        //if dist = 0 we don't need to move, location is reached and we can rest ! otherwise we move
        if(dist != 0)
        {
            float dx = (pos_x_reach - x)/dist;
            float dy = (pos_y_reach - y)/dist;

            this->x += speed*dx;
            this->y += speed*dy;
        }
        if(dist < height)
            action_state = Action::Rest;
}

Gender Specie::get_gender()
{
    return gender;
}

Action Specie::get_action_state()
{
    return action_state;
}

int Specie::get_x()
{
    return x;
}

int Specie::get_y()
{
    return y;
}

