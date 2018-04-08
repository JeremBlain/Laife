#include "general_functions.hpp"

float distance(int x1, int y1, int x2, int y2)
{
    int dist_x = x2 - x1;
    dist_x > 0 ? dist_x = dist_x : dist_x = - dist_x;

    int dist_y =  y2 - y1;
    dist_y > 0 ? dist_y = dist_y : dist_y = - dist_y;


    float dist = dist_x + dist_y; //L1 distance ! Not very accurate

    return dist;
}


float distance_squared(int x1, int y1, int x2, int y2)
{
    return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}


int generate_random_pos(int max, int offset, int excluded)
{
    int rand_number = 0 ;
    while(rand_number >= -excluded && rand_number <= excluded)
        rand_number = rand()%max-offset;

    return rand_number;
}

