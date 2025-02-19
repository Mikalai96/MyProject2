#include "Forest.h"
#include"Tree.h"
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "Russian");

    DeciduousForest deciduousForest;
    ConiferousForest coniferousForest;

    // Создаем деревья
    deciduousForest.addTree(std::make_shared<Oak>("Дуб1"));
    deciduousForest.addTree(std::make_shared<Oak>("Дуб2"));
    deciduousForest.addTree(std::make_shared<Birch>("Береза1"));

    coniferousForest.addTree(std::make_shared<Pine>("Сосна1"));
    coniferousForest.addTree(std::make_shared<Pine>("Сосна2"));

    // Попытка добавить неправильный тип дерева
    deciduousForest.addTree(std::make_shared<Pine>("Сосна3"));

    std::cout << "\nШум лиственного леса:" << std::endl;
    deciduousForest.wind();

    std::cout << "\nШум хвойного леса:" << std::endl;
    coniferousForest.wind();

    std::cout << "\nСтатистика по деревьям:" << std::endl;
    std::cout << "Количество дубов: " << Oak::getCount() << std::endl;
    std::cout << "Количество берез: " << Birch::getCount() << std::endl;
    std::cout << "Количество сосен: " << Pine::getCount() << std::endl;

    return 0;
}