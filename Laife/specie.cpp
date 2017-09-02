#include "specie.hpp"

/** Abstract class for vegetals and animals species
 *
 * */

Specie::Specie() : x(50), y(50)
{

}

Specie::Specie(int pos_x, int pos_y) : x(pos_x), y(pos_y)
{

}

void Specie::move(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}
