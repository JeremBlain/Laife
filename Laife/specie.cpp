#include "specie.hpp"

/** Abstract class for vegetals and animals species
 *
 * */

Specie::Specie() : x(100), y(100), action_state(Action::Rest), direction_angle(0),
                   weight(10), height(24), gender(Gender::Male), age(0)
{

}

Specie::Specie(int pos_x, int pos_y, int h) : x(pos_x), y(pos_y), action_state(Action::Rest),
                                       weight(10), height(h), gender(Gender::Male), age(0)
{
    direction_angle = (rand()%180)/180.0f*2*Constant::PI;
}

void Specie::move(int dv, float COS[], float SIN[])
{
    if(action_state == Action::Move)
    {
        int i = direction_angle*32/(Constant::PI);

        this->x += dv*COS[i%32];
        this->y += dv*SIN[ (i+16)%32];
    }
}
