#include "const.h"
#include "field.h"
#include "game.h"
#include "snake.h"

#include <windows.h>
#include <iostream>
#include <conio.h>
//#define AUTOMATIC

void Print(char* field, const int SIZE) {
	system("cls");
	std::cout << "\n";
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << border_symbol;
	}
	std::cout << '\n';
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << field[i];
	}
	std::cout << '\n';
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << border_symbol;
	}
};

int main() {
	system("cls");

	for (size_t i = 0; i < columns; i++)
	{
		field[i] = field_symbol;
	}

	snake_x[0] = snake_size;
	field[0] = border_symbol;
	field[columns - 1] = border_symbol;
	Print(field, columns);

	unsigned int user_case;
	std::cout << "\nInsert symble for determining the direction : right(->) or left(< -)";
	user_case = _getch();
	if (user_case != 224)
	{
		std::cout << "incorrect symbol\n";
	}
	else
	{
		user_case = _getch();
	}

	switch (user_case)
	{
	case DIRECTION::RIGHT_dir:
		field[snake_x[0]] = head_symbol;
		if (snake_x[0] > 1)
		{
			for (size_t i = snake_x[0] - 1; i > 0; i--)
			{
				field[i] = tail_symbol;
			}
		}
		Print(field, columns);
		
		std::cout<< "\nPress any key for start game\n";
		_getch();
		do
		{
			int tmp;
			tmp = field[columns - 2];
			for (size_t i = columns-2; i > 0; i--)
			{
				field[i] = field[i - 1];
			}
			field[1] = tmp;
			Print(field, columns);

#ifdef AUTOMATIC   
			Sleep(timeout);
				system("cls");
				if (_kbhit())      
				{
					user_case = _getch(); 
					if (user_case == 27)
					{
						game_on = false; 
					} 
				}
#else
			user_case = _getch();
				if (user_case == 27)
				{
					game_on = false;
				}
#endif

		} while (game_on);
		break;

	case DIRECTION::LEFT_dir:
		field[L - snake_x[0] + 1] = head_symbol;
		if (snake_x[0] > 1)
		{
			for (size_t i = L-snake_x[0]+2; i <= columns - 2; i++)
			{
				field[i] = tail_symbol;
			}
		}
		Print(field, columns);
		
		std::cout<< "\nPress any key for start game\n";
		_getch();
		do
		{
			int temp;
			temp = field[1];
			for (size_t i = 2; i <=columns - 2; i++)
			{
				field[i - 1] = field[i];
			}
			field[columns - 2] = temp;
			Print(field, columns);

#ifdef AUTOMATIC   
			Sleep(timeout);
			system("cls");
			if (_kbhit())
			{
				user_case = _getch();
				if (user_case == 27)
				{
					game_on = false;
				}
			}
#else
			user_case = _getch();
			if (user_case == 27)
			{
				game_on = false;
			}
#endif

		} while (game_on);
		break;
	default:
		std::cout << "Âû ââåëè íåêîððåêòíûé ñèìâîë";
	}

	system("cls");
	for (size_t i = 0; i < columns; i++)
	{
		field[i] = field_symbol;
	}

	std::cout << "Insert snake size=";
	std::cin >> snake_size;
	game_on = true;
	snake_x[0] = snake_size;
	field[0] = border_symbol;
	field[columns - 1] = border_symbol;
	Print(field, columns);
	
	std::cout << "\nInsert symble for determining the direction: right(->) or left(<-)";
	
	user_case = _getch();
	if (user_case!=224)
	{
		std::cout << "Incorrect symbol\n";
	}
	else
	{
		user_case = _getch();
	}
	switch (user_case)
	{
	case DIRECTION::RIGHT_dir:
		field[snake_x[0]] = head_symbol;
		if (snake_x[0]>1)
		{
			for (size_t i = snake_x[0]-1; i >0; i--)
			{
				field[i] = tail_symbol;
			}
		}
		Print(field, columns);

		std::cout << "\nPress any key for start game\n";
		_getch();
		do
		{
			int tmp;
			tmp = field[columns - 2];
			for (size_t i = columns-2; i > 0; i--)
			{
				field[i] = field[i - 1];
			}
			field[1] = tmp;
			Print(field, columns);

#ifdef AUTOMATIC   
			Sleep(timeout);
			system("cls");
			if (_kbhit())
			{
				user_case = _getch();
				if (user_case == 27)
				{
					game_on = false;
				}
			}
#else
			user_case = _getch();
			if (user_case == 27)
			{
				game_on = false;
			}
#endif

		} while (game_on);
		break;
	case DIRECTION::LEFT_dir:
		field[L - snake_x[0] + 1] = head_symbol;
		if (snake_x[0]>1)
		{
			for (size_t i = L-snake_x[0]+2; i <=columns-2; i++)
			{
				field[i] = tail_symbol;
			}
		}
		Print(field, columns);
		std::cout<< "\nPress any key for start game\n";

		_getch();
		do
		{
			int tmp;
			tmp = field[1];
			for (size_t i = 2; i <= columns-2; i++)
			{
				field[i - 1] = field[i];
			}
			field[columns - 2] = tmp;
			Print(field, columns);
#ifdef AUTOMATIC   
			Sleep(timeout);
			system("cls");
			if (_kbhit())
			{
				user_case = _getch();
				if (user_case == 27)
				{
					game_on = false;
				}
			}
#else
			user_case = _getch();
			if (user_case == 27)
			{
				game_on = false;
			}
#endif

		} while (game_on);
		break;
	default:
		std::cout << "Âû ââåëè íåêîððåêòíûé ñèìâîë";
		break;
	}
	return 0;
}