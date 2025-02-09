#include "Forest.h"
#include "Tree.h"

void Forest::addTree(const Tree& tree) {
    trees.push_back(tree);
}
size_t Forest::getTreesNumber() const {
    return trees.size();
}

Forest Forest::operator+(const Forest& other) const {
    Forest newForest = *this;
    newForest.trees.insert(newForest.trees.end(), other.trees.begin(), other.trees.end());
    return newForest;
}
void Forest::cutAll() {
    trees.clear();
}