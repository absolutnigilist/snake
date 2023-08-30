#include "snake.h"

void init_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, DIRECTION& direction, int  field_columns, int field_rows) {

    snake_x[0] = 2 + rand() % (field_columns - 2 - 2); 
    snake_y[0] = 2 + rand() % (field_rows - 2 - 2); 

    for (int i = 1; i < snake_size; i++) 
    {
        if (i == 1)
        {
            snake_x[1] = (rand() % 2) ? snake_x[0] - SIGN(snake_x[0] - (field_columns - 2) / 2) * 1 : snake_x[1] = snake_x[0]; 
            snake_y[1] = (snake_x[1] == snake_x[0]) ? snake_y[0] - SIGN(snake_y[0] - (field_rows - 2) / 2) * 1 : snake_y[1] = snake_y[0];
        }
        else 
        {
            snake_x[i] = (snake_y[i] == snake_y[i - 1]) ? snake_x[i - 1] - SIGN(snake_x[0] - (field_columns - 2) / 2) * 1 : snake_x[i] = snake_x[i - 1];
            snake_y[i] = (snake_x[i] == snake_x[i - 1]) ? snake_y[i - 1] - SIGN(snake_y[0] - (field_rows - 2) / 2) * 1 : snake_y[i] = snake_y[i - 1]; 
        }
    }

    if (snake_x[0] < L / 2)
    {
        direction = DIRECTION::RIGHT_dir;
    }
    else {
        direction = DIRECTION::LEFT_dir;
    }
}

void move_snake(unsigned int* snake_x, unsigned int* snake_y, int snake_size, const DIRECTION& direction, int  field_columns, int field_rows) {

    static DIRECTION tmp_direction;
    if (snake_size > 1) 
    {
        if ((tmp_direction == DIRECTION::LEFT_dir && direction == DIRECTION::LEFT_dir) ||
            (tmp_direction == DIRECTION::RIGHT_dir && direction == DIRECTION::LEFT_dir) ||
            (tmp_direction == DIRECTION::UP_dir && direction == DIRECTION::DOWN_dir) ||
            (tmp_direction == DIRECTION::DOWN_dir && direction == DIRECTION::UP_dir)) 
        {
            tmp_direction = tmp_direction;
        }
        else 
        {
            tmp_direction = direction;
        }
    }
    else 
    {
        tmp_direction = direction;
    }


    for (int i = snake_size - 1; i > 0; i--) 
    {
        snake_x[i] = snake_x[i - 1];
        snake_y[i] = snake_y[i - 1];
    }

    if (tmp_direction == DIRECTION::RIGHT_dir)
    {
        if (snake_x[0] >= (field_columns - 2))
        {
            snake_x[0] -= field_columns - 2;
        }
        snake_x[0]++;
    }

    if (tmp_direction == DIRECTION::LEFT_dir) 
    {
        if (snake_x[0] <= 1) 
        {
            snake_x[0] += field_columns - 2;
        }
        snake_x[0]--;
    }
    if (tmp_direction == DIRECTION::DOWN_dir)
    {
        if (snake_y[0] >= (field_rows - 2)) 
        {
            snake_y[0] -= field_rows - 2;
        }
        snake_y[0]++;
    }

    if (tmp_direction == DIRECTION::UP_dir) 
    {
        if (snake_y[0] <= 1)
        {
            snake_y[0] += field_rows - 2;
        }
        snake_y[0]--;
    }
}

void grow_snake(bool food_flag, int& snake_size) {
    if (!food_flag) 
    {
        snake_size++;
    }
}