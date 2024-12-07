#include <string>
namespace Shapes  // Определяем пространство имен Shapes
{
    enum class SHAPE
    {

        CIRCLE,
        SQUARE,
        TRIANGLE,

    };    // Определяем перечисление SHAPE

    void printShape(Shapes::SHAPE fg); // Функция вывода названия фигуры по первому условию задачи
  
    void compare(std::string name); // Функция сравнения введенного наименования с наименованием условия по доп условию задачи
    
}