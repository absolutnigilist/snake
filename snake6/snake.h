#pragma once
#include "const.h"
#include "food.h"
#include <stdlib.h>

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

void init_snake(unsigned int* snake_x, int snake_size, DIRECTION& direction);
void move_snake(unsigned int* snake_x, int snake_size, DIRECTION& direction);
void grow_snake(bool food_flag, int& snake_size);

