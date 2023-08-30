#include "const.h"
#include "field.h"
#include "food.h"
#include "game.h"
#include "snake.h"
#include "winconsole.h"

#include <windows.h>
#define AUTOMATIC

int main() {

    SNAKE mysnake = { 0 };
    FIELD myfield = { 0,0,nullptr };
    FOOD myfood = { 0 };
    GAME mygame = { 0 };

    init_game_struct(mygame, mysnake, myfield, myfood);
    system("cls");
    create_field_struct(myfield);
    init_snake_struct(mysnake, myfield);
    generate_food_struct(myfood, myfield);
    init_field_struct(myfield);
    print_field_struct(myfield);
    std::cout << "Please enter any key for start game";

    keyboard_scan_struct(mysnake, mygame);

    while (mygame.game_on) 
    {
        setCursorPosition(0, 0);
        check_eating_struct(mysnake, myfood);
        generate_food_struct(myfood, myfield);
        grow_snake_struct(myfood, mysnake);
        move_snake_struct(mysnake, myfield);
        check_game_struct(mysnake, mygame, myfield);
        check_snake_struct(mysnake, mygame, myfield);
        clear_field_struct(myfield);
        set_food_struct(myfield, myfood);
        set_snake_struct(myfield, mysnake);
        print_field_struct(myfield);

#ifdef AUTOMATIC       
        if (_kbhit())
#endif
        {
            keyboard_scan_struct(mysnake, mygame);
        }
        Sleep(mygame.timeout);
    }
    destroy_field_struct(myfield);
}