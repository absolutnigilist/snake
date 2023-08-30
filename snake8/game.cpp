#include "game.h"

void init_game(unsigned int& timeout, int& snake_size, int& field_columns, int& field_rows, bool& game_on, bool& food_flag) {
    srand(time(0));
    timeout = 100;
    snake_size = 5;
    game_on = false;// true;
    food_flag = false;

    std::cout << "Enter the number of lines:";
    std::cin >> field_rows;
    std::cout << std::endl;
    std::cout << "Enter the number of columns:";
    std::cin >> field_columns;
    std::cout << std::endl;

}

void set_snake(char** field, int field_columns, int field_rows, const unsigned int* snake_x, const unsigned int* snake_y, int snake_size) {
    for (int i = 0; i < snake_size; i++) 
    {
        if ((snake_x[i] != 0 && snake_x[i] != (field_columns - 1)) && (snake_y[i] != 0 && snake_y[i] != (field_rows - 1))) 
        {
            if (i == 0) 
            {
                field[snake_x[i]][snake_y[i]] = head_symbol;
            }
            else
            {
                field[snake_x[i]][snake_y[i]] = tail_symbol;
            }
        }
    }
}

void set_food(char** field, int food_x, int food_y) {

    field[food_x][food_y] = food_symbol;
}

void check_game(int snake_size, bool& game_on) {
    if (game_on) {
        if (snake_size >= L) {
            game_on = false;
        }
        else {
            game_on = true;
        }
    }
}

void check_snake(const unsigned int* snake_x, const unsigned int* snake_y, int snake_size, bool& game_on, int field_columns, int field_rows) {
    if (game_on) 
    {
        if (snake_x[0] > 0 && snake_x[0] < field_columns - 1)
        {
            game_on = true;
        }
        else
        {
            game_on = false;
        }
        if (snake_y[0] > 0 && snake_y[0] < field_rows - 1)
        {
            game_on = true;
        }
        else 
        {
            game_on = false;
        }

        for (int i = 1; i < snake_size; i++) 
        {
            if ((snake_x[0] == snake_x[i]) && (snake_y[0] == snake_y[i]))
            {
                game_on = false;
                break;
            }
            else 
            {
                game_on = true;
            }
        }
    }
}

void check_eating(const unsigned int* snake_x, const unsigned int* snake_y, bool& food_flag, int food_x, int food_y) {
    
    if (snake_x[0] == food_x && snake_y[0] == food_y) 
    {
        food_flag = false;
    }
    else 
    {
        food_flag = true;
    }
}

void clear_snake(char** field, int* snake_x, int* snake_y, int snake_size) {

    for (int j = 0; j < snake_size; j++)
    {
        for (int i = 0; i < snake_size; i++) 
        {
            field[snake_x[i]][snake_y[j]] = field_symbol;
        }
    }
}

void keyboard_scan(DIRECTION& direction, bool& game_on) {

    unsigned char direction1 = 0, direction2 = 0;

    direction1 = _getch();
    if (KEYS::ESC == direction1) {
        game_on = false;
        return;
    }
    else
        game_on = true;
    {
        if (224 == direction1)
        {
            direction2 = _getch();
            switch (direction2) 
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