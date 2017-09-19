#ifndef VEGETAL_SPECIE_HPP
#define VEGETAL_SPECIE_HPP

#include "specie.hpp"

class VegetableSpecie : public Specie
{
public:
    VegetableSpecie();
    VegetableSpecie(int pos_x, int pos_y, Gender g);

    ~VegetableSpecie();

    void draw_sprite(QPainter *painter);
    void change_behavior();
    VegetableSpecie* breed(Specie &male);
};

#endif // VEGETAL_SPECIE_HPP
