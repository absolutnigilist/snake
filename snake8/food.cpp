#include "food.h"
#include <stdlib.h>

void generate_food(bool food_flag, int& food_x, int& food_y, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size, int field_columns, int field_rows) {
	if (!food_flag)
	{
		food_x = 1 + rand() % (field_columns - 2);
		food_y = 1 + rand() % (field_rows - 2);// 
	}
}

void init_food(void) {

}