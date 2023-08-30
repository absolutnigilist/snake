#pragma once
#include "const.h"
#include "food.h"
#include "snake.h"
#include "field.h"

#include <stdlib.h>

#define MAX(A, B)	((A)<(B)?(B):(A))
#define MIN(A, B)	((A)>(B)?(B):(A))
#define SIGN(A)	    ((A)<0?(-1):(1))

struct FOOD;

struct SNAKE {
    int snake_size;
    DIRECTION direction;
    unsigned int snake_x[L * H];
    unsigned int snake_y[H * L];
};

//void init_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, DIRECTION& direction, int  field_columns, int field_rows);
//void move_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, const DIRECTION& direction, int  field_columns, int field_rows);
//void grow_snake(bool food_flag, int& snake_size);
void init_snake_struct(SNAKE& mysnake, const FIELD& myfield);
void move_snake_struct(SNAKE& mysnake, const FIELD& myfield);
void grow_snake_struct(const FOOD& fd, SNAKE& mysnake);