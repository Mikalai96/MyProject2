#include <iostream>


int main()
{
	int** array = new int* [3];
	for (int i = 0; i < 3; i++) 
	{
		array[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) {
			array[i][j] = i * j;
		}
	}
	std::cout << "Array: \n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << "\n";
	}
	delete[] array;

	return 0;
}