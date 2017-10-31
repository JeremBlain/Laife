#ifndef VEGETAL_SPECIE_HPP
#define VEGETAL_SPECIE_HPP

#include "specie.hpp"
#include "pollen.h"

class VegetableSpecie : public Specie
{
public:
    VegetableSpecie();
    VegetableSpecie(int pos_x, int pos_y, int n, Gender g);

    ~VegetableSpecie();

    void draw_sprite(QPainter *painter); //the color depends on the gender
    void change_behavior();

    //breeding related methods
    VegetableSpecie* breed(int num_species, int pos_x, int pos_y);
    Pollen* send_pollen();
    void copulate();
};

#endif // VEGETAL_SPECIE_HPP
