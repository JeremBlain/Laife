
#pragma once

/** File for all the enumerations
 *
 * Will be :
 *  - Action
 *  - Social Behavior
 *  - Individual Behavior
 *  - Maybe genes
 */


/* this enum is for animal specie.
 * vegetal species only use rest and breed) */
enum Action : int { Rest, Move, Sleep, Find_Food, Find_Water, Find_Specie, Drink, Eat, Breed, Play };

namespace Constant
{
    const int NUMBER_ACTIONS = 10; //don't forget to update it when you add or remove an action... !
}

