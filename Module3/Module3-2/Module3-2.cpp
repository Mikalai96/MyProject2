#include <iostream>
#include <random>

int main()
{
    int min_value1 = -5, min_value2 = -5;
    int max_value1 = 5, max_value2 = 5;

    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib1(min_value1, max_value1);
    std::uniform_int_distribution<> distrib2(min_value2, max_value2);
    int a = 0;

    for (int i = 0; i < 101; ++i) 
    {
       a = a + distrib1(gen);
       if (a == 50)
        {           
           std::cout << "Win 1" << " " << "\n";
           i = 101;
           return 0;
        }
       a = a + distrib2(gen);
       if (a == 50)
       {
           std::cout << "Win 2" << " " << "\n";
           i = 101;
           return 0;
       }
       if (i == 100)
       {
           std::cout << "Game over" << "\n";
       }                      
              
    }
    std::cout << std::endl;
   
}