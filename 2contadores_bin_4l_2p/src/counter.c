#include "room.h"

// ====================================================================================================
// Private variables
// ====================================================================================================
static double temp = 0;

// ====================================================================================================
// Private functions
// ====================================================================================================
static double
calculate_area(double len, double brth)
{
    temp = len * brth;
    return temp;
}


static double
calculate_volume(double len, double brth, double hgt)
{
    return len * brth * hgt;
}


// ====================================================================================================
// Public function definitions
// ====================================================================================================
double
room_calculate_area(room_t * p_self)
{
    return calculate_area(p_self->length, p_self->breadth);
}

double
room_calculate_volume(room_t * p_self)
{
    return calculate_volume(p_self->length, p_self->breadth, p_self->height);
}