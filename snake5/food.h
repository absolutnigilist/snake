#pragma once
#include "snake.h"

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

extern bool food_flag;
extern int food_x;

void generate_food();