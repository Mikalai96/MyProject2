#include "Tree.h"
#include <iostream>
#include <string>
#include <vector>

class Tree
{
public:
    enum class TreeType {
        conifers,
        deciduous
    };
    Tree(const std::string& name, TreeType type) : name(name), type(type) {
        id = ++count;
    }
    Tree(const Tree& other) : name(other.name), type(other.type) {
        id = ++count;
    }
    void wind() const {
        std::cout << "Tree " << name << " ID: " << id << std::endl;
    }
    int getID() const {
        return id;
    }
    const std::string& getName() const {
        return name;
    }
    static int getCount() {
        return count;
    }
private:

    std::string name;
    TreeType type;
    int id;
    static int count;
};
int Tree::count = 0;