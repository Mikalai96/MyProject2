#include <iostream>
#include "ClassBook.h"

int main()
{
	Book Firstbook("Krew Elfow", "Andrzej Sapkowski", 2022, "978-5-17-118219-9");
	Firstbook.printInfo();
	std::cout << "Copy:" << std::endl;
	Book Secondbook = Firstbook;
	Secondbook.printInfo();
	std::cout <<"Getters:" << std::endl;
	std::cout << "Title: " << Firstbook.getTitle() << std::endl;
	std::cout << "Author: " << Firstbook.getAuthor() << std::endl;
	std::cout << "Year: " << Firstbook.getYear() << std::endl;
	std::cout << "ISBN: " << Firstbook.getISBN() << std::endl;
	return 0;

}

