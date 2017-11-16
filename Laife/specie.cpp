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

/*
bool Specie::collision(int left_x, int top_y, int right_x, int bottom_y, int obj_num)
{
    if(number == obj_num) //if the specie is the same as the specie sent
        return false;

    float dist = distance(pos_x_reach, pos_y_reach, x, y); //float for keeping the float operations after with dx and dy !

    float dx = (pos_x_reach - x)/dist;
    float dy = (pos_y_reach - y)/dist;

    int bound_x=0, bound_y=0;

    if(dx > 0)
        bound_x = x+dx*Constant::SPEED+height/2.0;
    else
        bound_x = x+dx*Constant::SPEED-height/2.0;

    if(dy > 0)
        bound_y = y+dy*Constant::SPEED+height/2.0;
    else
        bound_y = y+dy*Constant::SPEED-height/2.0;


    //if the next step the specie is on the bouding box of something else
    if( (bound_x >= left_x && bound_x <= right_x) && (bound_y >= top_y && bound_y <= bottom_y) )
        return true;

    return false;
}*/


bool Specie::collision(QRect obj_box, int obj_num)
{
    if(obj_num == ID)
        return false;

    float dist = distance(pos_x_reach, pos_y_reach, x, y); //float for keeping the float operations after with dx and dy !

    float dx = (pos_x_reach - x)/dist;
    float dy = (pos_y_reach - y)/dist;

    QRect self_box(x+dx*Constant::SPEED-height/2.0, y+dy*Constant::SPEED-height/2.0, height, height);

    if(self_box.intersects(obj_box) == true)
        return true;

    return false;
}

void Specie::change_direction_obstacle(Specie *obstacle)
{
    int obs_x = obstacle->get_x(), obs_y = obstacle->get_y();
    float dist = distance(x, x, obs_x, obs_y); //float for keeping the float operations after with dx and dy !

    dx = -dy; //-(y - obs_y)/dist;
    dy = dx; //(x-obs_y)/dist;

    std::cout<<dx<<" "<<dy<<std::endl;

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

