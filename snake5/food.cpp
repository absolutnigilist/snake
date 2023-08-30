#include "food.h"
#include <stdlib.h>

bool food_flag;
int food_x;

void generate_food() {
	if (!food_flag)
	{
		food_x = (rand() % 2) ? ((3 < (MIN(snake_x[0], snake_x[snake_size - 1]))) ? (1 + rand() % (MIN(snake_x[0], snake_x[snake_size - 1]) - 2)) : (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])))) : (MAX(snake_x[0], snake_x[snake_size - 1]) + rand() % (L - 1 - MAX(snake_x[0], snake_x[snake_size - 1])));
	}
}