#include "game.h"


bool game_on;
unsigned int timeout;

void init_game() {
	srand(time(0));
	timeout = 100;
	snake_size = 1;
	game_on = true;
	food_flag = false;
}
void set_snake() {
	for (size_t i = 0; i < snake_size; i++)
	{
		if (snake_x[i] != 0 && snake_x[i] != (columns - 1))//if (snake_x[i]!=0)
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

void set_food() {
	field[food_x] = food_symbol;
}

void check_game() {
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

void check_snake(){
	if (game_on)
	{
		if (snake_x[0] > 0 && snake_x[0] < (columns - 1))//if (snake_x[0]<=0||snake_x[0]>=columns-1)
		{
			game_on = true;//game_on = false;
		}
		else
		{
			game_on = false;//game_on = true;
		}
	}
}

void check_eating() {
	//if (game_on)
	//{
		if (snake_x[0]==food_x)
		{
			food_flag = false;
		}
		else
		{
			food_flag = true;
		}
	//}
}

void clear_snake() {
	/*for (size_t i = 0; i < snake_size; i++)
	{
		if (snake_x[i]!=0)
		{
			if (i==0)
			{
				field[snake_x[i]] = field_symbol;
			}
			else
			{
				field[snake_x[i]] = field_symbol;
			}
		}
	}*/
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

void keyboard_scan() {
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