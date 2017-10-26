#ifndef GENERAL_FUNCTIONS_HPP
#define GENERAL_FUNCTIONS_HPP

/* this file and his cpp are all the functions which don't belong to a specific class but could be useful for them */

#include "time.h"
#include "iostream"

/*this comptue the L1 distance, be careful.
 * The reason is : this is computationaly more efficient. And don't need math library !
 */
float distance(int x1, int y1, int x2, int y2);

//creates a randomly generated number between -max-offset and max-offset, excluded numbers between -excluded and excluded
int generate_random_pos(int max, int offset, int excluded);

#endif // GENERAL_FUNCTIONS_HPP
