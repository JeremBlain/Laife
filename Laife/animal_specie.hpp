#ifndef ANIMAL_SPECIE_HPP
#define ANIMAL_SPECIE_HPP


#include "specie.hpp"

class animal_specie : public Specie
{
public:
    animal_specie();
    animal_specie(int pos_x, int pos_y);

    void draw_sprite(QPainter *painter);
    void change_behavior();
};

#endif // ANIMAL_SPECIE_HPP
