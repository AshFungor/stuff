#include <iostream>
#include <vector>
#include "bin-search-tree.cpp"

#define COUT(str) std::cout << str << std::endl;

int main(void) {
    std::vector<int> init_arr(3, 3);
    BinSearchTree<int> tree(init_arr);

    COUT("initialized tree with 3 numbers that equal 3!")
    COUT("adding number 4 to tree...")
    tree.add(4);
    COUT("adding number 2 to tree...")
    tree.add(2);
    std::cout << "tree max is " << tree.max() << ", tree min is " 
    << tree.min() << std::endl;

    return 0;
}