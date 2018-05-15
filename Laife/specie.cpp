#include "specie.hpp"

/** Abstract class for vegetals and animals species
 *
 * */

Specie::Specie() : x(100), y(100), action_state(Action::Rest), pos_x_reach(x), pos_y_reach(y), dx(0), dy(0), move_step(0), ID(0),
                   weight(10), height(24), gender(Gender::Male), age(0), breedable(0)
{

}

Specie::Specie(int pos_x, int pos_y, int id, int h, Gender g) : x(pos_x), y(pos_y), action_state(Action::Rest), dx(0), dy(0), move_step(0), ID(id),
                                       weight(10), height(h), gender(g), age(0), breedable(0)
{
    //default : the specie will reach a point near it
    pos_x_reach = x + rand()%100-50;
    pos_y_reach = y + rand()%100-50;
}


Specie::~Specie()
{
}

void Specie::compute_direction()
{
    float dist = distance(pos_x_reach, pos_y_reach, x, y); //float for keeping the float operations after with dx and dy !

    if(dist != 0)
    {
        dx = (pos_x_reach - x)/dist;
        dy = (pos_y_reach - y)/dist;
    }
    else
    {
        dx = 0; dy = 0;
    }

    move_step = Constant::MOVE_STEP;
}


void Specie::move(int speed)
{
        float dist = distance(pos_x_reach, pos_y_reach, x, y); //float for keeping the float operations after with dx and dy !

        //if dist = 0 we don't need to move, location is reached and we can rest ! otherwise we move
        if(dist != 0)
        {
            this->x += speed*dx;
            this->y += speed*dy;
        }

        if(dist < height)
            action_state = Action::Rest;
}

void Specie::decrement_move_step()
{
    if(move_step > 0) //move step's minimum is 0 !
        --move_step;
}


bool Specie::collision(int x_obj, int y_obj, int radius_obj, int obj_num)
{
    if(obj_num == ID) //don't want to know if it's collide with itself.... it will
        return false;

    float dist_squared = distance_squared(x+dx*Constant::SPEED, y+dy*Constant::SPEED, x_obj, y_obj);

    // 2 disks intersect if distance between their centers are less than the sum of their radius (d <= r1+r2 )
    if(dist_squared <= (height/2 + radius_obj + Constant::OFFSET_COLLISION) * (height/2 + radius_obj + Constant::OFFSET_COLLISION) )
        return true;

    return false;
}

void Specie::change_direction_obstacle(Specie *obstacle)
{
    int obs_x = obstacle->get_x(), obs_y = obstacle->get_y();
    float dist = distance(x, y, obs_x, obs_y); //float for keeping the float operations after with dx and dy !

    dx = -(y - obs_y)/dist;
    dy = (x-obs_x)/dist;

    //if the specie collide the obstacle even with the 90° turn, turn it the opposite way !
    if(this->collision(obs_x, obs_y, obstacle->get_height()/2, obstacle->get_ID()))
    {
        dx = (y - obs_y)/dist;
        dy = -(x-obs_x)/dist;

        //if the specie collide again (striaght, left and right... go where you came from !...
        if(this->collision(obs_x, obs_y, obstacle->get_height()/2, obstacle->get_ID()))
        {
            dx = -dx; dy = -dy;

            //finally, if there is no way out... stay here
            if(this->collision(obs_x, obs_y, obstacle->get_height()/2, obstacle->get_ID()))
               dx = 0; dy = 0;
        }
    }


    move_step = Constant::MOVE_STEP;
}

void Specie::decrement_breedable()
{
    if(breedable > 0) //breedable's minimum is 0 !
        --breedable;
}

void Specie::rest()
{
    action_state = Action::Rest;
}

Gender Specie::get_gender()
{
    return gender;
}

int Specie::get_move_step()
{
    return move_step;
}

int Specie::get_breedable()
{
    return breedable;
}

Action Specie::get_action_state()
{
    return action_state;
}

int Specie::get_x()
{
    return x;
}

int Specie::get_y()
{
    return y;
}

int Specie::get_ID()
{
    return ID;
}

int Specie::get_height()
{
    return height;
}

