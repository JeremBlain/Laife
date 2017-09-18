#ifndef ANIMAL_SPECIE_HPP
#define ANIMAL_SPECIE_HPP


#include "specie.hpp"

class AnimalSpecie : public Specie
{
public:
    AnimalSpecie();
    AnimalSpecie(int pos_x, int pos_y);

    void draw_sprite(QPainter *painter);
    void change_behavior();
    Specie* breed(Specie &male);

private :

    // Needs : from 0 to 100, with 0 = need, 100 = full and doesn't need
    int hunger;
    int thirst;
    int hapiness;
    int tiredness;

};

#endif // ANIMAL_SPECIE_HPP
