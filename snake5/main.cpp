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

int main() {
	init_game();
	init_snake();
	generate_food();
	init_field();
	set_food();
	set_snake();
	print_field();

	std::cout << "Please enter any key for start game";

	keyboard_scan();
	while (game_on)
	{
		system("cls");
		check_eating();
		generate_food();
		grow_snake();
		move_snake();
		check_game();
		check_snake();
		clear_field();
		set_food();
		set_snake();
		print_field();

		std::cout << "QUIT: ESC\tLEFT: <\tRIGHT: >\tUP: ^\tDOWN: v\n";

#ifdef AUTOMATIC
		if (_kbhit())
#endif
		{
			keyboard_scan();
		}
		Sleep(timeout);
	}
}