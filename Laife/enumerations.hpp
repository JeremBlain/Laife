
#pragma once

#include <math.h>

/** File for all the enumerations and constants
 *
 * Will be :
 *  - Action
 *  - Social Behavior
 *  - Individual Behavior
 *  - Maybe genes
 */

namespace Constant
{
    const int NUMBER_ACTIONS = 10; //don't forget to update it when you add or remove an action... !
    const float PI = 3.1415;
    const int SPEED = 3; //speed for moving
    const int MOVE_STEP = 30;

    const int ANIMALS_SIZE = 24;
    const int PLANTS_SIZE = 30;
    const int POLLEN_SIZE = 10;
    const int FOOD_SIZE = 15;

    const int BREEDED = 100;
    const int COPULATE = 50;
    const int DISTANCE_MIN_FIND_PARTNER = 250;
    const int DISTANCE_MAX_BREED = ANIMALS_SIZE + 10;
    const int OFFSET_COLLISION = 5;

    const int TICK = 30; //millisecond
}

namespace Test
{
    const int animal_specie_x_1 = 300;
    const int animal_specie_y_1 = 500;
    const int animal_specie_x_2 = 350;
    const int animal_specie_y_2 = 450;
    const int animal_specie_x_3 = 500;
    const int animal_specie_y_3 = 800;
    const int animal_specie_x_4 = 250;
    const int animal_specie_y_4 = 460;
    const int animal_specie_x_5 = 250;
    const int animal_specie_y_5 = 510;

    const int plant_specie_x_1 = 480;
    const int plant_specie_y_1 = 390;
    const int plant_specie_x_2 = 520;
    const int plant_specie_y_2 = 340;
    const int plant_specie_x_3 = 800;
    const int plant_specie_y_3 = 290;

    const int food_x_1 = 200;
    const int food_y_1 = 200;
    const int food_x_2 = 400;
    const int food_y_2 = 400;
    const int food_x_3 = 275;
    const int food_y_3 = 205;
    const int food_x_4 = 500;
    const int food_y_4 = 260;

    const int collisiontest_1_x = 200;
    const int collisiontest_1_y = 200;

    const int collisiontest_2_x = 240;
    const int collisiontest_2_y = 200;

    const int collisiontest_3_x = 200;
    const int collisiontest_3_y = 260;

    const int collisiontest_4_x = 240;
    const int collisiontest_4_y = 260;

    const int collisiontest_5_x = 230;
    const int collisiontest_5_y = 230;
}


/* this enum is for animal specie.
 * vegetal species only use rest and breed) */
enum Action : int { Rest, Sleep, Move, Find_Food, Find_Water, Find_Partner, Drink, Eat, Breed, Play };

enum Gender : int { Male, Female };



