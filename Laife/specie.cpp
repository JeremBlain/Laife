#include "specie.hpp"

/** Abstract class for vegetals and animals species
 *
 * */

Specie::Specie() : x(100), y(100), action_state(Action::Rest), direction_angle(0),
                   weight(10), height(24), gender(Gender::Male), age(0)
{

}

Specie::Specie(int pos_x, int pos_y, int h, Gender g) : x(pos_x), y(pos_y), action_state(Action::Rest),
                                       weight(10), height(h), gender(g), age(0)
{
    direction_angle = rand()*2*Constant::PI;
}

void Specie::move(int dv, float COS[])
{
    if(action_state == Action::Move)
    {
        int i = direction_angle*32/(Constant::PI);

        this->x += dv*COS[i%33];
        this->y += dv*COS[ (i+16)%33];
    }
}

Gender Specie::get_gender()
{
    return gender;
}
