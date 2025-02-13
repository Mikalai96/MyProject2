#include "Forest.h"
#include "Tree.h"
#include <iostream>
#include <string>
#include <vector>

    Forest() {};

    void addTree(const Tree& tree) {
        trees.push_back(tree);
    }
    size_t getTreesNumber() const {
        return trees.size();
    }

    Forest operator+(const Forest& other) const {
        Forest newForest = *this;
        newForest.trees.insert(newForest.trees.end(), other.trees.begin(), other.trees.end());
        return newForest;
    }
    void cutAll() {
        trees.clear();
    }
 

