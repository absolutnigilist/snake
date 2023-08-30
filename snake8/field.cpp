#include "field.h"

void init_field(char** field, int field_columns, int field_rows) {

	for (int i = 0; i < field_rows; i++) 
	{
		for (int j = 0; j < field_columns; j++)
		{
			
			if ((i > 0 && i < (field_rows - 1)) && (j > 0 && j < (field_columns - 1)))
			{
				field[j][i] = field_symbol;;
			}
			else 
			{
				field[j][i] = border_symbol;
			}
		}
	}

}

void clear_field(char** field, int field_columns, int field_rows) {

	for (int i = 1; i < field_rows - 1; i++) {
		for (int j = 1; j < field_columns - 1; j++) {
			field[j][i] = field_symbol;
		}
	}
}

void print_field(char** field, int field_columns, int field_rows) {
	
	for (int i = 0; i < field_rows; i++)
	{
		for (int j = 0; j < field_columns; j++)
		{
			std::cout << field[j][i];
		}
		std::cout << std::endl;
	}
}

bool create_field(char**& field, char*& sub_field, int field_columns, int field_rows) {

	if (field_columns * field_rows) 
	{
		
		char* tmp_sub_field = new char[field_columns * field_rows];
		char** tmp_field = new char* [field_rows];
		for (int i = 0; i < field_columns; i++)
		{
			tmp_field[i] = tmp_sub_field + i * field_rows;
		}
		
		sub_field = tmp_sub_field;
		field = tmp_field;
	}
	if (field)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void destroy_field(char**& field, char*& sub_field, int field_columns, int field_rows) {

	if (field_columns * field_rows) 
	{
		delete[] field;
		delete[] sub_field;

		sub_field = nullptr;
		field = nullptr;
	}

}