#pragma once
#include "snake.h"

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

void generate_food(bool food_flag, int& food_x, const unsigned int* snake_x, int snake_size);
void init_food();