#pragma once
#include "const.h"
#include "food.h"
#include <stdlib.h>

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

extern DIRECTION direction;
extern unsigned int snake_size;
extern unsigned int snake_x[];

void init_snake();
void move_snake();
void grow_snake();

