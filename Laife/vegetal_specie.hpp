#ifndef VEGETAL_SPECIE_HPP
#define VEGETAL_SPECIE_HPP

#include "specie.hpp"

class vegetal_specie : public Specie
{
public:
    vegetal_specie();
    vegetal_specie(int pos_x, int pos_y);

    void draw_sprite(QPainter *painter);
    void change_behavior();
};

#endif // VEGETAL_SPECIE_HPP
