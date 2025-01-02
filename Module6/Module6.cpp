#include <iostream>
#include <cstring>

void reverseString(char* str)
{
    int length = strlen(str); // Получаем длинну строки
    for (int i = 0; i < length / 2; i++) // Выполнение цикла до середины строки
    {        
        char temp = str[i];// Временная переменная для хранения символа начала строки
        str[i] = str[length - 1 - i]; // Меняем местами символы
        str[length - 1 - i] = temp; // Подстановка сохранненного символа в конец 
    }
}
int main()
{
    const int LENGTH = 100;
    char str[LENGTH];

    std::cout << "Module 6\n"<< "Enter the string\n";

    std::cin.getline(str, LENGTH);
    reverseString(str);
    std::cout <<"Reverse your string: " << str;
    return 0;
}