#include "Forest.h"
#include <iostream>

void Forest::wind() const {
    for (const auto& tree : trees) {
        tree->wind();
    }
}

size_t Forest::getTreesCount() const {
    return trees.size();
}

void DeciduousForest::addTree(std::shared_ptr<Tree> tree) {
    if (tree->getType() == TreeType::DECIDUOUS) {
        trees.push_back(tree);
    }
    else {
        std::cout << "Ошибка: В лиственный лес можно добавлять только лиственные деревья!" << std::endl;
    }
}

void ConiferousForest::addTree(std::shared_ptr<Tree> tree) {
    if (tree->getType() == TreeType::CONIFEROUS) {
        trees.push_back(tree);
    }
    else {
        std::cout << "Ошибка: В хвойный лес можно добавлять только хвойные деревья!" << std::endl;
    }
}