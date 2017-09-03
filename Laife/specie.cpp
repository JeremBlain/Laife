#include "specie.hpp"

/** Abstract class for vegetals and animals species
 *
 * */

Specie::Specie() : x(50), y(50), action_state(Action::Rest)
{

}

Specie::Specie(int pos_x, int pos_y) : x(pos_x), y(pos_y), action_state(Action::Rest)
{

}

void Specie::move(int dx, int dy)
{
    if(action_state == Action::Move)
    {
        std::cout<<"Moving"<<std::endl;
        this->x += dx;
        this->y += dy;
    }
}
