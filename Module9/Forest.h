#pragma once
#include "Tree.h"
#include <vector>

class Forest {        
public:
   void addTree(const Tree& tree);
   size_t getTreesNumber() const;
   Forest operator+(const Forest& other) const;
   void cutAll();
private:
        std::vector<Tree> trees;
};

