#include <iostream>

int main()
{
    std::cout << "Module 4\n";

    std::cout << "Enter number\n";

    int nmbr, shift;

    std::cin >> nmbr;

    if ( nmbr%2==0 && nmbr>0 ) // Использована конструкция if-else
    {
        shift = nmbr << 2;
        std::cout << "Result shift left: " << shift << "\n";
    }
    else
    {
        shift = nmbr >> 2;
        std::cout << "Result shift right: " << shift << "\n";
    }

    std::cout << "Enter number\n"; // Использован условный тернарный оператор
    
    std::cin >> nmbr;

    nmbr % 2 == 0 && nmbr > 0 ? std::cout << "Result shift left: " << (nmbr << 2) : 
        std::cout << "Result shift right: " << (nmbr >> 2);
}