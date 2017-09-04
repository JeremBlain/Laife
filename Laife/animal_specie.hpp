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

private :

    // Needs : from 0 to 100, with 0 = need, 100 = full and doesn't need
    int hunger;
    int thirst;
    int hapiness;
    int tiredness;

};

#endif // ANIMAL_SPECIE_HPP
