#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> rnd = {1,2,3,4,5,6,7,8,9,10};
    for (int& num : rnd) 
    {
        num = rand() % 100+1;
    }
    for (int num : rnd) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
    std::sort(rnd.begin(), rnd.end());
    for (int num : rnd)
    {
        std::cout << num << " ";
    }
    return 0;
}