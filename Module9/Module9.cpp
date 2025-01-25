#include <iostream>
#include "Forest.h"
#include "Tree.h"

int main()
{
    
    std::cout << "Module9\n";
    
    Tree Oak("Oak", Tree::TreeType::deciduous);
    Oak.wind();
    std::cout << "Total count of trees " << Tree::getCount() << std::endl;
    Tree Oak2 = Oak;
    Oak2.wind();
    std::cout << "Total count of trees " << Tree::getCount() << std::endl;
   
   Forest forest1;
    forest1.addTree(Oak);
    forest1.addTree(Tree("Pine", Tree::TreeType::conifers));
    std::cout << "Total count of trees in forest1 " << Tree::getCount() << std::endl;

    Forest forest2;
    forest2.addTree(Tree("Birch", Tree::TreeType::deciduous));
    std::cout << "Total count of trees in forest2 " << Tree::getCount() << std::endl;

    Forest bigForest = forest1 + forest2; 

    std::cout << "Total count in big forest " << bigForest.getTreesNumber() << std::endl;
   
    bigForest.cutAll();
    std::cout << "Total count in big forest " << bigForest.getTreesNumber() << std::endl;
    return 0;
}