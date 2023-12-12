#include "const.h"
#include "field.h"
#include "food.h"
#include "game.h"
#include "snake.h"

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#define AUTOMATIC

void Print(char* field, const int SIZE) {
	
	srand(time(NULL));
	system("cls");
	field[0] = border_symbol;
	field[columns - 1] = border_symbol;
	std::cout << "\n";
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << border_symbol;
	}
	
	std::cout << "\n";

	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << field[i];
	}

	std::cout << "\n";

	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << border_symbol;
	}
	std::cout << "\n";
};

int main() {
	start_game();

	for (int i = 0; i < snake_size; i++)
	{
		if (i == 0)
		{
			field[snake_x[i]] = head_symbol;
		}
		else
		{
			field[snake_x[i]] = tail_symbol;
		}
	}

	if (!food_flag)
	{
		do
		{
			food_x = rand() % L + 1;
		} while (field[food_x]!=field_symbol);
		food_flag = true;
	}
	field[food_x] = food_symbol;
	Print(field, columns);
	
	unsigned int user_case;
	std::cout << "Please enter any key for start game";
	game_on = false;
	user_case = _getch();
	if (user_case != 27)
	{
		game_on = true;

	}
	else
	{
		return 0;
	}
	
	while (game_on)
	{
		std::cout << "\nInsert symbol for determining the direction: right(->) or left(<-)";

#ifdef AUTOMATIC   

		if (_kbhit())
		{
			user_case = _getch();
			if (user_case == 27)
			{
				game_on = false;
			}
			else if (user_case != 224)
			{
				std::cout << "Incorrect symbol";
			}
			else
			{
				user_case = _getch();
			}
		}
#else
		user_case = _getch();
		if (user_case == 27)
		{
			game_on = false;
		}
		else if (user_case != 224)
		{
			std::cout << "Incorrect symbol";
		}
		else
		{
			user_case = _getch();
		}
#endif

		switch (user_case)
		{
		case DIRECTION::RIGHT_dir:
			game_on = true;
			break;
		case DIRECTION::LEFT_dir:
			game_on = true;
			break;
		default:
			break;
		}

		for (size_t i = snake_size - 1; i < 0; i--)
		{
			snake_x[i] = snake_x[i - 1];
		}

		if (user_case == DIRECTION::RIGHT_dir)
		{
			snake_x[0]++;
			if (snake_x[0] >= columns - 1)
			{
				snake_x[0] = 1;
			}
		}

		if (user_case == DIRECTION::LEFT_dir)
		{
			snake_x[0]--;
			if (snake_x[0] < 1)
			{
				snake_x[0] = columns - 1;
			}
		}

		if (!food_flag)
		{
			do
			{
				food_x = rand() % L + 1;
			} while (field[food_x] != field_symbol);
			food_flag = true;
		}

		if (snake_x[0] == food_x)
		{
			snake_size++;
			if (snake_size == L)
			{
				std::cout << "Game over!\n";
				return 0;
			}
			food_flag = false;
		}

		for (int i = 1; i < columns - 1; i++)
		{
			field[i] = field_symbol;
		}

		field[food_x] = food_symbol;
		for (int i = 0; i < snake_size; i++)
		{
			if (i == 0)
			{
				field[snake_x[i]] = head_symbol;
			}
			else
			{
				field[snake_x[i]] = tail_symbol;
			}
		}
		Sleep(timeout);
		Print(field, columns);
	}
	
	return 0;
}