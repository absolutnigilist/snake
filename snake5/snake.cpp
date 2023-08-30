#include "snake.h"


unsigned int snake_size;
unsigned int snake_x[L];
DIRECTION direction;

void init_snake() {
	for (size_t i = 0; i < snake_size; i++)
	{
		snake_x[i] = (i == 0) ? 2 + rand() % (L - 2) : snake_x[i - 1] - SIGN(snake_x[0] - L / 2) * 1;
	}
	if (snake_x[0]<L/2)
	{
		direction = DIRECTION::RIGHT_dir;
	}
	else
	{
		direction = DIRECTION::LEFT_dir;
	}
}

void move_snake() {
	/*for (size_t i = snake_size-1; i >0; i--)
	{
		snake_x[i] = snake_x[i - 1];
	}
	if (direction==DIRECTION::RIGHT_dir)
	{
		snake_x[0]++;
	}
	if (direction==DIRECTION::LEFT_dir)
	{
		snake_x[0]--;
	}*/
	for (size_t i = snake_size - 1; i > 0; i--)
	{
		snake_x[i] = snake_x[i - 1];
	}
	if (direction == DIRECTION::RIGHT_dir)
	{
		if (snake_x[0] >= (columns - 2))
		{
			snake_x[0] -= columns - 2;
		}
		snake_x[0]++;
	}
	if (direction == DIRECTION::LEFT_dir)
	{
		if (snake_x[0] <= 1)
		{
			snake_x[0] += columns - 2;
		}
		snake_x[0]--;
	}
}
void grow_snake() {
	if (!food_flag)
	{
		snake_size++;
	}
}