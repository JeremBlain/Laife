
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
    const int BREEDED = 100;
    const int DISTANCE_MIN_FIND_PARTNER = 250;
    const int TICK = 100; //millisecond
}

namespace Test
{
    const int first_animal_specie_x = 250;
    const int first_animal_specie_y = 100;

    const int first_vegetable_specie_x = 333;
    const int first_vegetable_specie_y = 450;
}


/* this enum is for animal specie.
 * vegetal species only use rest and breed) */
enum Action : int { Rest, Move, Sleep, Find_Food, Find_Water, Find_Partner, Drink, Eat, Breed, Play };

enum Gender : int { Male, Female };



