#include "Header.h"

void writeElement(int* array, int size)
{
	std::cout << "Enter the number\n";

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> array[i];
	}
}
void printElement(int* array, int size)
{
	std::cout << "Array element value: ";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << array[i] << " ";
	}
}