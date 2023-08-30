#include "game.h"

void init_game(unsigned int& timeout, int& snake_size, bool& game_on, bool& food_flag) {
	srand(time(0));
	timeout = 100;
	snake_size = 1;
	game_on = true;
	food_flag = false;
}
void set_snake(char* field, const unsigned int* snake_x, int snake_size) {
	for (size_t i = 0; i < snake_size; i++)
	{
		if (snake_x[i]!=0&&snake_x[i]!=(columns-1))
		{
			if (i==0)
			{
				field[snake_x[i]] = head_symbol;
			}
			else
			{
				field[snake_x[i]] = tail_symbol;
			}
		}
	}
}

void set_food(char* field, int food_x) {
	field[food_x] = food_symbol;
}

void check_game(int snake_size, bool& game_on) {
	if (game_on)
	{
		if (snake_size>=L)
		{
			game_on = false;
		}
		else
		{
			game_on = true;
		}
	}
}

void check_snake(unsigned int* snake_x, bool& game_on){
	if (game_on)
	{
		if (snake_x[0]>0&&snake_x[0]<(columns-1))
		{
			game_on = true;
		}
		else
		{
			game_on = false;
		}
	}
}

void check_eating(unsigned int* snake_x, bool& food_flag, int food_x) {
		if (snake_x[0]==food_x)
		{
			food_flag = false;
		}
		else
		{
			food_flag = true;
		}
}

void clear_snake(char* field, int* snake_x, int snake_size) {
	for (size_t i = 0; i < snake_size; i++)
	{
		for (size_t j = 0; j < snake_size; j++)
		{
			if (snake_x[i] != 0)
			{
				if (i == 0)
				{
					field[snake_x[i]] = field_symbol;
				}
				else
				{
					field[snake_x[i]] = field_symbol;
				}
			}
		
		}
	}
}

void keyboard_scan(DIRECTION& direction, bool& game_on) {
	unsigned char direction_1 = 0;
	unsigned char direction_2 = 0;

	direction_1 = _getch();
	if (KEYS::ESC == direction_1)
	{
		game_on = false;
		return;
	}
	else
	{
		if (224==direction_1)
		{
			direction_2 = _getch();
			switch (direction_2) 
			{
			case KEYS::LEFT:
				direction = DIRECTION::LEFT_dir;
				game_on = true;
				break;
			case KEYS::RIGHT:
				direction = DIRECTION::RIGHT_dir;
				game_on = true;
				break;
			case KEYS::UP:
				direction = DIRECTION::UP_dir;
				game_on = true;
				break;
			case KEYS::DOWN:
				direction = DIRECTION::DOWN_dir;
				game_on = true;
				break;
			case KEYS::ESC:
				game_on = false;
				break;
			default:
				game_on = true;
			}
		}
	}
}