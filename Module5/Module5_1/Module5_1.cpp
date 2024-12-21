#include <iostream>
#include <string>
#include "Header.h"

int main()
{
    std::string name;
    std::cout << "Enter name of figure: circle, triangle, square " << std::endl;
    std::cin >> name;
    
    Shapes::compare(name);
    
    
    return 0;
    
    /*Shapes::SHAPE Shape = Shapes::SHAPE::CIRCLE; //Функционал по задаче 1 без доп условия
    Shapes::printShape(Shape);*/
}