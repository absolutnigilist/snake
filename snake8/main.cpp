﻿#include "const.h"
#include "field.h"
#include "food.h"
#include "game.h"
#include "snake.h"
#include "winconsole.h"

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>


#define AUTOMATIC

int main() {

    int snake_size_m;
    bool game_on_m;
    unsigned int timeout_m;
    bool food_flag_m;
    int food_x_m;
    int food_y_m;
    int columns_m = 0;
    int rows_m = 0;   

    init_game(timeout_m, snake_size_m, columns_m, rows_m, game_on_m, food_flag_m);
    system("cls");
    char** field_m = nullptr;
    char* sub_field;
   
    game_on_m = create_field(field_m, sub_field, columns_m, rows_m);

    DIRECTION direction_m;
    unsigned int snake_x_m[L * H];
    unsigned int snake_y_m[H * L];

    init_snake(snake_x_m, snake_y_m, snake_size_m, direction_m, columns_m, rows_m);
    generate_food(food_flag_m, food_x_m, food_y_m, snake_x_m, snake_y_m, snake_size_m, columns_m, rows_m);
    init_field(field_m, columns_m, rows_m);
    print_field(field_m, columns_m, rows_m);
    
    std::cout << "Please enter any key for start game";

    keyboard_scan(direction_m, game_on_m);

    while (game_on_m) 
    {
        setCursorPosition(0, 0);
        check_eating(snake_x_m, snake_y_m, food_flag_m, food_x_m, food_y_m);
        generate_food(food_flag_m, food_x_m, food_y_m, snake_x_m, snake_y_m, snake_size_m, columns_m, rows_m);
        grow_snake(food_flag_m, snake_size_m);
        move_snake(snake_x_m, snake_y_m, snake_size_m, direction_m, columns_m, rows_m);
        check_game(snake_size_m, game_on_m);
        check_snake(snake_x_m, snake_y_m, snake_size_m, game_on_m, columns_m, rows_m);
        clear_field(field_m, columns_m, rows_m);
        set_food(field_m, food_x_m, food_y_m);
        set_snake(field_m, columns_m, rows_m, snake_x_m, snake_y_m, snake_size_m);
        print_field(field_m, columns_m, rows_m);
        

#ifdef AUTOMATIC       
        if (_kbhit())
#endif
        {
            keyboard_scan(direction_m, game_on_m);
        }
        Sleep(timeout_m);
    }
    destroy_field(field_m, sub_field, columns_m, rows_m);
}