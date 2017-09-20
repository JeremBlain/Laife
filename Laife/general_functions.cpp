
float distance(int x1, int x2, int y1, int y2)
{
    int dist_x = x2 - x1;
    dist_x > 0 ? dist_x = dist_x : dist_x = - dist_x;

    int dist_y =  y2 - y1;
    dist_y > 0 ? dist_y = dist_y : dist_y = - dist_y;


    float dist = dist_x + dist_y; //L1 distance ! Not very accurate

    return dist;
}
