#include "field.h"

void init_field(char (*field)[rows]) {
	
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if ((i > 0 && i < (H+1)) && (j > 0 && j < (L + 1)))
			{
				field[j][i] = field_symbol;
			}
			else
			{
				field[j][i] = border_symbol;
			}
		}
	}
}

void clear_field(char(*field)[rows]) {
	
	for (size_t i = 1; i <= H; i++)
	{
		for (size_t j = 1; j <=L; j++)
		{
			field[j][i] = field_symbol;
		}
	}
}

void print_field(char(*field)[rows]) {
	
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			std::cout << field[j][i];
		}
		std::cout << std::endl;
	}
}