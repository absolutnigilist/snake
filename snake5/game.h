#pragma once
#include "const.h"
#include "field.h"
#include "food.h"
#include "snake.h"
#include <ctime>
#include <conio.h>

extern unsigned int timeout;
extern bool game_on;

void start_game();
void init_game();
void set_snake();
void set_food();
void check_snake();
void check_game();
void check_eating();
void clear_snake();
void keyboard_scan();