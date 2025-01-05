#include <iostream>
#include <memory> 

// ������� ����� ������������� ������ ��� �������
void writeElement(int* array, int size);

// ������� ��� ���������� ����� ���� ��������� �������
void sumElem(const std::weak_ptr<int[]>& weakArray, int size, int& result);

// ������� ��� ���������� ������������� � ������������ �������� �������
void MinMax(const std::weak_ptr<int[]>& weakArray, int size, int& maxValue, int& minValue);