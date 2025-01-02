#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int[]> array = std::make_unique<int[]>(10);
	
	std::cout << "Enter the number\n";

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> array[i];
	}
	std::cout << "Array element value: ";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << array[i]<<" ";
	}
	std::cout << "\n";

	int min_value = array[0];
	int max_value = array[0];
	
	for (int i = 0; i < 10; ++i) 
	{
		if (array[i] < min_value) 
		{
			min_value = array[i];
		}
		if (array[i] > max_value) 
		{
			max_value = array[i];
		}
	}

	std::cout << "Minimum value: " << min_value << "\n";

	std::cout << "Maximum value: " << max_value << "\n";

	return 0;
}

