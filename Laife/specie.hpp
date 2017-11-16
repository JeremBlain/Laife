#ifndef SPECIE_HPP
#define SPECIE_HPP

#include <QPainter>
#include "enumerations.hpp"
#include "general_functions.hpp"
#include "iostream"

class Specie
{
public:
    Specie();
    Specie(int pos_x, int pos_y, int id, int h, Gender g);

    virtual ~Specie() = 0;

    virtual void draw_sprite(QPainter *painter) = 0; //the color depends on the gender
    virtual void change_behavior() = 0;
    virtual Specie* breed(int num_species, int pos_x, int pos_y) = 0;
    virtual void copulate() = 0; //Spcie is now in breed state. This the step before the species mahe the new born

    void compute_direction();
    void move(int speed);    
    void decrement_move_step();
    bool collision(QRect obj_box, int obj_num); //if the specie collide to something (something with bounding box coords nt parameters
    void change_direction_obstacle(Specie *obstacle); //change the direction of the specie according to the position of the obstacle

    void decrement_breedable();
    void rest();

    // GETTER & SETTER
    Gender get_gender();
    int get_move_step();
    int get_breedable();
    Action get_action_state();
    int get_x();
    int get_y();
    int get_ID();
    int get_height();

protected :
    int x, y; //coords
    Action action_state; //Behavior of the specie

    int pos_x_reach; //coordinates the specie want to reach
    int pos_y_reach;
    float dx; //direction to move
    float dy;
    int move_step; //the move step is the number of movement (each tick) done before recompute the direction

    int ID; //each individual have a number


    // Caracteristics :
    int weight;
    int height;
    Gender gender;
    int age;
    int breedable; //the specie can reproduce if breedable is 0, cannot otherwise (breedable >=0)
};

#endif // SPECIE_HPP
