#ifndef PLANT_SPECIE_HPP
#define PLANT_SPECIE_HPP

#include "specie.hpp"
#include "pollen.h"

class PlantSpecie : public Specie
{
public:
    PlantSpecie();
    PlantSpecie(int pos_x, int pos_y, int n, Gender g);

    ~PlantSpecie();

    void draw_sprite(QPainter *painter); //the color depends on the gender
    void change_behavior();

    //breeding related methods
    PlantSpecie* breed(int num_species, int pos_x, int pos_y);
    Pollen send_pollen();
    void copulate();
};

#endif // PLANT_SPECIE_HPP
