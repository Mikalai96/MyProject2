#pragma once
#include <vector>
#include <memory>
#include "Tree.h"

class Forest {
protected:
    std::vector<std::shared_ptr<Tree>> trees;

public:
    virtual ~Forest() = default;
    virtual void addTree(std::shared_ptr<Tree> tree) = 0;
    void wind() const;
    size_t getTreesCount() const;
};

class DeciduousForest : public Forest {
public:
    void addTree(std::shared_ptr<Tree> tree) override;
};

class ConiferousForest : public Forest {
public:
    void addTree(std::shared_ptr<Tree> tree) override;
};