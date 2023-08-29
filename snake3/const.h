#pragma once

const int columns = 10;
char tail_symbol = '#';
char head_symbol = '@';
char field_symbol = ' ';
char border_symbol = '*';
const int L = columns - 2;
enum KEYS { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27 };
enum DIRECTION{RIGHT_dir=KEYS::RIGHT,LEFT_dir=KEYS::LEFT};
