#include "Tree.h"

// Класс дерево
Tree::Tree(const std::string& name, TreeType type) : name(name), treeType(type) {}

TreeType Tree::getType() const {
    return treeType;
}

std::string Tree::getName() const {
    return name;
}

// Реализация класса дуб
int Oak::count = 0;

Oak::Oak(const std::string& name) : Tree(name, TreeType::DECIDUOUS) {
    ++count;
}

Oak::~Oak() {
    --count;
}

void Oak::wind() const {
    std::cout << "Дуб " << name << " шумит листвой" << std::endl;
}

int Oak::getCount() {
    return count;
}

// Реализация класса сосна
int Pine::count = 0;

Pine::Pine(const std::string& name) : Tree(name, TreeType::CONIFEROUS) {
    ++count;
}

Pine::~Pine() {
    --count;
}

void Pine::wind() const {
    std::cout << "Сосна " << name << " шумит иголками" << std::endl;
}

int Pine::getCount() {
    return count;
}

// Реализация класса береза
int Birch::count = 0;

Birch::Birch(const std::string& name) : Tree(name, TreeType::DECIDUOUS) {
    ++count;
}

Birch::~Birch() {
    --count;
}

void Birch::wind() const {
    std::cout << "Береза " << name << " шелестит листьями" << std::endl;
}

int Birch::getCount() {
    return count;
}