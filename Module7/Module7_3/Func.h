#include <iostream>
#include <vector>
#include <memory>

void print(int numbr);
void print(float numbr);
void print(std::string word);
void print(char* str);
void print(int* arr, int size);
void print(const std::vector<int>& vec);
void print(const std::shared_ptr<int>& ptr);
void print(const std::unique_ptr<double>& ptr);
