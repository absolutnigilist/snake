#include "const.h"
#include "game.h"
#include "snake.h"
#include <windows.h>
#include <iostream>

int main() {

	if (snake_size == 1)
	{
		for (size_t i = 0; i < columns; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			std::cout << head_symbol;
			Sleep(timeout);
			system("cls");
		}
	}
	else
	{

		for (size_t i = 0; i < columns; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			for (size_t k = 0; k < snake_size - 1; k++)
			{
				std::cout << tail_symbol;
			}
			std::cout << head_symbol;
			Sleep(timeout);
			system("cls");
		}
	}
	return 0;
}