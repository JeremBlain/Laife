#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <QTimer>
#include <memory>

#include "animal_specie.hpp"
#include "plant_specie.hpp"


class GameState
{
public:
    GameState();

    std::vector<AnimalSpecie*> animals_array;
    std::vector<PlantSpecie*> vegans_array;
    std::vector<Pollen> pollens_array;

    //all these methods check if the species have the correct behavior (ex : move() check if the behavior of species is Move)
    void move(); //move all the animals species

    //test all entities to avoid collisison with animal. Should be used when moving and it modfies the direction of movement. return true if a collision is detected and avoided.
    void avoid_collision(AnimalSpecie *animal);
    //test all entities to avoid collisison with hitbox. The num_species is the number linked with the hitbox entities
    //this one should be used when create a new entities !
    bool collision(int x_obj, int y_obj, int radius_obj);

    bool generate_position_new_born(Specie *mother, int &pos_x, int &pos_y); //generate a position which do not collide with other entities

    void find_partner(); //try to find a partner for all the species
    void breeding();
    void breeding_animals(AnimalSpecie *female, AnimalSpecie *male);
    void breeding_plants(PlantSpecie *female);
    void change_behavior();
    void grow_old(); //method to grow old species, like his age, his breedable state, etc...


    /** These functions have test purpose. Only for testing some parameters and functions */
    void init_test_game();
    void clear_array();
    void test_breed(); //used it after init_test_game !
    void test_collision();
};

#endif // GAMESTATE_HPP
