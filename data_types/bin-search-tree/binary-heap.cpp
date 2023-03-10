// template class
// binary heap

// OVERVIEW
// Допустим, что нам необходимо иметь структуру данных, хранящую
// множество пар ключ-значение и поддерживающую (наиболее эффективно)
// следующие запросы к ней:
// - Получить элемент с максимальным ключом – getMax()
// - Извлечь (удалить) элемент с максимальным ключом – extractMax()
// - Вставить новый элемент – insert(key, value)
// - Изменить значение ключа имеющегося элемента – changeKey(ptr, new)
// Эффективной реализацией описанной структуры данных является binary
// heap – двоичная (бинарная) пирамида (куча) – сбалансированное двоичное
// дерево, удовлетворяющее правилу пирамиды:
// Элемент каждого узла больше или равен элементам-потомкам.

// includes
#include <stdexcept>
#include <utility>
#include <vector>
#include <climits>

// protection from multiple includes
#ifndef BHTREE00_H_
#define BHTREE00_H_

// class signature definition
template<typename T>
class BinaryHeap {

private:
    // we store key-value pair
    std::vector<std::pair<int, T>> tree;
    const int unmapped_region_value = INT_MIN + 1;
    // why this even exists?
    // void change_key(const int& ptr, const int& new_key);
    // sift - просеивание
    void sift_up(const int& ptr);
    void sift_down(const int& ptr);
    const int default_tree_size = 8;

public:
    BinaryHeap<T>();
    BinaryHeap<T>(const std::vector<std::pair<int, T>>& init_array);
    T get_max() const;
    T extract_max();
    void insert(const int& key, const T& value);

};

// member class definition
// easiest ones are sift_up and sift_down
template<typename T>
void BinaryHeap<T>::sift_up(const int& ptr) {
    if (ptr == 1) { return; } // reached root element
    if (tree[ptr >> 1].first < tree[ptr].first) {
        std::swap(tree[ptr >> 1], tree[ptr]);
        sift_up(ptr >> 1);
    }
    else { return; } // nothing to do
}

template<typename T>
void BinaryHeap<T>::sift_down(const int& ptr) {
    // reached a leaf
    if (ptr << 1 >= tree.size() || tree[ptr].first == unmapped_region_value) { return; }
    else if (tree[ptr].first < std::max(tree[ptr << 1].first, tree[ptr << 1 | 1].first)) {
        if (tree[ptr << 1] > tree[ptr << 1 | 1]) {
            std::swap(tree[ptr << 1], tree[ptr]);
            sift_down(ptr << 1); 
        }
        else { 
            std::swap(tree[ptr << 1 | 1], tree[ptr]);
            sift_down(ptr << 1 | 1); 
        }
    }
    else { return; } // nothing to do
}

template<typename T>
// basically return root element
T BinaryHeap<T>::get_max() const { return tree[1].second; }


template<typename T>
void BinaryHeap<T>::insert(const int& key, const T& value) {
    // look for first best position for new element
    int current_ptr = 1;
    while (current_ptr < tree.size() && tree[current_ptr].first != unmapped_region_value) {
        ++current_ptr;
    }
    if (current_ptr >= tree.size()) {
        tree.resize(tree.size() * 2, std::pair<int, T>(unmapped_region_value, T()));
    }
    tree[current_ptr] = std::pair<int, T>(key, value);
    // sift new element up
    sift_up(current_ptr);
}

template<typename T>
T BinaryHeap<T>::extract_max() {
    // look for lowest and most left element
    int current_ptr = tree.size() - 1;
    while (current_ptr >= 1 && tree[current_ptr].first == unmapped_region_value) {
        --current_ptr;
    }
    if (!current_ptr) { throw std::runtime_error("heap is out of elements"); }
    // now just put on top
    T ret_value = tree[1].second;
    tree[1] = tree[current_ptr];
    tree[current_ptr] = std::pair<int, T>(unmapped_region_value, T());
    sift_down(1);
    return ret_value;
}

// constructors
template<typename T>
BinaryHeap<T>::BinaryHeap(const std::vector<std::pair<int, T>>& init_array) {
    tree = std::vector<std::pair<int, T>>(init_array.size(), std::pair<int, T>(unmapped_region_value, T()));
    for (const std::pair<int, T>& el : init_array) {
        insert(el.first, el.second);
    }
}

template<typename T>
BinaryHeap<T>::BinaryHeap() {
    tree = std::vector<std::pair<int, T>>(default_tree_size, std::pair<int, T>(unmapped_region_value, T()));
}

#endif