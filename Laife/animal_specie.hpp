#ifndef ANIMAL_SPECIE_HPP
#define ANIMAL_SPECIE_HPP


#include "specie.hpp"

class AnimalSpecie : public Specie
{
public:
    AnimalSpecie();
    AnimalSpecie(int pos_x, int pos_y, int n, Gender g);

    ~AnimalSpecie();

    void draw_sprite(QPainter *painter); //the color depends on the gender
    void change_behavior(); //if the animal rest, it has the probabilty to change is behavior

    //Breeding behavior
    AnimalSpecie* breed(int num_species); //we check if the other species is a male
    void copulate();
    //Check the animals species array and take the first species that is close enough
    //then we set the position to reach
    void find_partner(std::vector<AnimalSpecie *> &animals_array);

private :

    // Needs : from 0 to 100, with 0 = need, 100 = full and doesn't need
    int hunger;
    int thirst;
    int hapiness;
    int tiredness;

};

#endif // ANIMAL_SPECIE_HPP
