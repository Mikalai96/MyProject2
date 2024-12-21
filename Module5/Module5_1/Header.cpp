#include <iostream>
#include <string>
#include"Header.h"

void Shapes::printShape(Shapes::SHAPE fg)
{
    switch (fg)
    {
    case Shapes::SHAPE::CIRCLE:
        std::cout << "circle" << std::endl;
        break;
    case Shapes::SHAPE::SQUARE:
        std::cout << "square" << std::endl;
        break;
    case Shapes::SHAPE::TRIANGLE:
        std::cout << "triangle" << std::endl;
        break;
    }
}
void Shapes::compare(std::string name)
{
    if (name == "circle")
    {
        Shapes::SHAPE Shape = Shapes::SHAPE::CIRCLE;
        Shapes::printShape(Shape);
    }
    if (name == "triangle")
    {
        Shapes::SHAPE Shape = Shapes::SHAPE::TRIANGLE;
        Shapes::printShape(Shape);
    }

    if (name == "square")
    {
        Shapes::SHAPE Shape = Shapes::SHAPE::SQUARE;
        Shapes::printShape(Shape);
    }
}
