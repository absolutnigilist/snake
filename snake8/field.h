#pragma once
#include"const.h"
#include <iostream>

void init_field(char** field, int field_columns, int field_rows);
void clear_field(char** field, int field_columns, int field_rows);
void print_field(char** field, int field_columns, int field_rows);
bool create_field(char**& sub_field, char*& field, int field_columns, int field_rows);
void destroy_field(char**& sub_field, char*& field, int field_columns, int field_rows);