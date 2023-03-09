// template class

// includes
#include <vector>
#include <utility>

// protection from multiple includes
#ifndef BSTREE00_H_
#define BSTREE00_H_

template<typename T>
class BinSearchTree {

private:
    std::vector<std::pair<bool, T>> tree;
    const static short default_tree_size = 16;
    void recursive_move(int node);

public:
    BinSearchTree();
    BinSearchTree(const std::vector<T>& init_array);
    T min() const;
    T max() const;
    void add(const T& value);
    void remove(const T& value);
    T next(const T& value) const;

};

template<typename T>
void BinSearchTree<T>::recursive_move(int node) {
    if (tree[node * 2].first) { tree[node] = tree[node * 2]; }
    if (tree[node * 2 + 1].first) { tree[node + 1] = tree[node * 2 + 1]; }
}

template<typename T>
BinSearchTree<T>::BinSearchTree() {
    tree = std::vector<std::pair<bool, T>>(default_tree_size, std::pair<bool, T>(false, T()));
}

template<typename T>
BinSearchTree<T>::BinSearchTree(const std::vector<T>& init_array) {
    // almost always size of array multiplied by 4 should be enough
    // anyway vector handles that
    tree = std::vector<std::pair<bool, T>>(init_array.size() * 4, std::pair<bool, T>(false, T()));
    for (const T& element : init_array) { this->add(element); }
}

template<typename T>
T BinSearchTree<T>::max() const {
    short child = 1; // start with root element
    // iterate trough right branches
    while (child < tree.size() && tree[child].first) { child = child * 2 + 1; }
    return tree[(child - 1) / 2].second;
}

template<typename T>
T BinSearchTree<T>::min() const {
    short child = 1; // start with root element
    // iterate trough left branches
    while (child < tree.size() && tree[child].first) { child = child * 2; }
    return tree[child / 2].second;
}

template<typename T>
void BinSearchTree<T>::add(const T& value) {
    // first we need to search for value in tree
    short child = 1; // we begin with root
    while (tree[child].first) {
        if (tree[child].second > value) { child = child * 2; }
        else if (tree[child].second <= value) { child = child * 2 + 1; }
        if (tree.size() <= child) { tree.resize(tree.size() * 2, std::pair<bool, T>(false, T())); }
    }
    // search until we find an empty space for new element
    tree[child] = std::pair<bool, T>(true, value);
}

template<typename T>
void BinSearchTree<T>::remove(const T& value) {
    // first we find the element
    short child = 1; // we begin with root
    while (tree[child].first && tree[child].second != value) {
        if (tree[child].second > value) { child = child * 2; }
        else if (tree[child].second <= value) { child = child * 2 + 1; }
    }
    // now there are three situations:
    // - element is leaf
    // - element has one child
    // - element has full family
    if (!tree[child * 2].first && !tree[child * 2 + 1].first) // first situation
    { tree[child] = std::pair<bool, T>(false, T()); }
    // basically sum with mod 2, we need only one condition to be true
    else if ((tree[child * 2].first + tree[child * 2 + 1].first) % 2) { 
        // we just move this child and its children to deleted node
        if (tree[child * 2].first) { tree[child] = tree[child * 2]; }
        else { tree[child] = tree[child * 2 + 1]; }

    }
}

template<typename T>
T BinSearchTree<T>::next(const T& value) const { return T(); }

#endif