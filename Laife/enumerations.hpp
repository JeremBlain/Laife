
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
    const int SPEED = 3; //speed for mowvng

    const int BREEDED = 100;
    const int COPULATE = 50;
    const int DISTANCE_MIN_FIND_PARTNER = 250;
    const int DISTANCE_MAX_BREED = 30;

    const int POLLEN_SIZE = 10;

    const int TICK = 100; //millisecond
}

namespace Test
{
    const int first_animal_specie_x = 300;
    const int first_animal_specie_y = 500;
    const int second_animal_specie_x = 350;
    const int second_animal_specie_y = 450;

    const int first_vegetable_specie_x = 480;
    const int first_vegetable_specie_y = 390;
    const int second_vegetable_specie_x = 520;
    const int second_vegetable_specie_y = 340;

    const int collisiontest_1_x = 200;
    const int collisiontest_1_y = 200;

    const int collisiontest_2_x = 260;
    const int collisiontest_2_y = 200;

    const int collisiontest_3_x = 200;
    const int collisiontest_3_y = 260;

    const int collisiontest_4_x = 260;
    const int collisiontest_4_y = 260;

    const int collisiontest_5_x = 230;
    const int collisiontest_5_y = 230;
}


/* this enum is for animal specie.
 * vegetal species only use rest and breed) */
enum Action : int { Rest, Sleep, Move, Find_Food, Find_Water, Find_Partner, Drink, Eat, Breed, Play };

enum Gender : int { Male, Female };



