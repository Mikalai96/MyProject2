#include <vector>
#include <string>
#include "Tree.h"

class Forest {
public:

    Forest();

    void addTree(const Tree& tree);
    size_t getTreesNumber() const;

    Forest operator+(const Forest& other) const;
    void cutAll();
private:
    std::vector<Tree> trees;
};

