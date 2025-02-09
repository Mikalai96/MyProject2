#pragma once
#include <string>
#include <iostream>

enum class TreeType {
    conifers,
    deciduous
}; 
class Tree
{
public:
    Tree(const std::string& name, TreeType type);
    Tree(const Tree& other);
    void wind() const;
    int getID() const;
    const std::string& getName() const;
    static int getCount();
private:
    std::string name;
    TreeType type;
    int id;
    static int count;
};

