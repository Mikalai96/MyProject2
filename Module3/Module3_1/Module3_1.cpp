#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 1;
    while (a<=10)
    {
        cout << a * b << "\t";
        if (b < 10)
        {
            b++;
        }
        else
        {
            cout << "\n";
            a++;
            b = 1;
        }
    }
 cout << "\n";
    for (int a = 1; a <= 10; a++)
    {
        for (int b = 1; b <= 10; b++)
        {
            cout << a * b << "\t";
        }
        cout << "\n";
    }
cout << "\n";
    a = 0;
    do
    {        
        //cout << a * b << "\t";      
        a++;
        for (int b = 1; b <= 10; b++)
        {
            cout << a * b << "\t";
        }
        cout << "\n";
    } while (a < 10);     
}
