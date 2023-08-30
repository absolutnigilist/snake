#pragma once
const int columns = 16;
const int rows = 32;
const char tail_symbol = '#';
const char head_symbol = '@';
const char food_symbol = '+';
const char field_symbol = ' ';
const char border_symbol = '*';
const int L = (columns-2);
const int H = (rows - 2);
enum KEYS { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27 };
enum DIRECTION{RIGHT_dir,LEFT_dir, UP_dir, DOWN_dir};
