#include <string>
namespace Shapes  // ���������� ������������ ���� Shapes
{
    enum class SHAPE
    {

        CIRCLE,
        SQUARE,
        TRIANGLE,

    };    // ���������� ������������ SHAPE

    void printShape(Shapes::SHAPE fg); // ������� ������ �������� ������ �� ������� ������� ������
  
    void compare(std::string name); // ������� ��������� ���������� ������������ � ������������� ������� �� ��� ������� ������
    
}