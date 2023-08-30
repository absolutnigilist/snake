#include "field.h"

char field[columns];

void init_field() {
	const int rows = 1;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if ((i > 0 && i < (rows - 1)) || (j > 0 && j < (L + 1)))
			{
				field[j] = field_symbol;
			}
			else
			{
				field[j] = field_symbol;
			}
		}
	}
}

void clear_field() {
	const int rows = 1;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 1; j <=L; j++)
		{
			field[j] = field_symbol;
		}
	}
}

void print_field() {
	const int rows = 1;
	for (size_t i = 0; i < columns; i++)
	{
		std::cout << border_symbol;
	}
	std::cout<<std::endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			std::cout << field[j];
		}
		std::cout << std::endl;
	}
	for (size_t i = 0; i < columns; i++)
	{
		std::cout << border_symbol;
	}
	std::cout << std::endl;
}