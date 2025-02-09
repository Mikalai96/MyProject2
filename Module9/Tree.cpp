#include "Tree.h"
#include <string>
#include <iostream>
#include <vector>

int Tree::count = 0;


    Tree::Tree(const std::string& name, TreeType type) : name(name), type(type) {
        id = ++count;
    }
    Tree::Tree(const Tree& other) : name(other.name), type(other.type) {
        id = ++count;
    }
    void  Tree::wind() const {
        std::cout << "Tree " << name << " ID: " << id << std::endl;
    }
    int  Tree::getID() const {
        return id;
    }
    const std::string& Tree::getName() const {
        return name;
    }
    int  Tree::getCount() {
        return count;
    }

