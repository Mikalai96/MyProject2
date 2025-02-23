#pragma once
#include <string>
#include <iostream>

enum class TreeType {
    CONIFEROUS,
    DECIDUOUS
};

class Tree {
protected:
    std::string name;
    TreeType treeType;
    int id;

public:
    Tree(const std::string& name, TreeType type);
    virtual ~Tree() = default;

    virtual void wind() const = 0;
    TreeType getType() const;
    std::string getName() const;
};

class Oak : public Tree {
private:
    static int count;
public:
    Oak(const std::string& name);
    ~Oak();
    void wind() const override;
    static int getCount();
};

class Pine : public Tree {
private:
    static int count;
public:
    Pine(const std::string& name);
    ~Pine();
    void wind() const override;
    static int getCount();
};

class Birch : public Tree {
private:
    static int count;
public:
    Birch(const std::string& name);
    ~Birch();
    void wind() const override;
    static int getCount();
};