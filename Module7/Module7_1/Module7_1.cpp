#include <iostream>
#include <memory>
#include "Header.h"

int main()
{
	std::unique_ptr<int[]> array = std::make_unique<int[]>(10);
	writeElement(array.get(), 10);
	printElement(array.get(), 10);
	
	return 0;
}