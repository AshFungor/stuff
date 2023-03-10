#include <iostream>
#include <vector>
#include <algorithm>

#include "binary-heap.cpp"

#define COUT(str) std::cout << str << std::endl;
#define PAIR(arg1,arg2) std::pair<int, char>(arg1, arg2)
#define PRINT_ARRAY(arr) for (auto el : arr) std::cout << el << ' '; std::cout << std::endl;

// sorting algorithm based on binary heap
std::vector<int> bh_sort(const std::vector<int>& arr) {
    // first we add all elements to heap
    std::vector<std::pair<int, int>> init_arr(arr.size());
    std::transform(arr.begin(), arr.end(), init_arr.begin(), 
    [](int value) { return std::pair<int, int>(value, value); });
    BinaryHeap<int> heap(init_arr);
    std::vector<int> res_arr(arr.size());
    // then just extract the most
    for (int iter = res_arr.size() - 1; iter >= 0; --iter)
        res_arr[iter] = heap.extract_max();
    return res_arr;
}

int main(void) {
    std::vector<std::pair<int, char>> vec({
        PAIR(1, 'a'), PAIR(2, 'b'), PAIR(3, 'c')
    });
    BinaryHeap<char> heap(vec);
    COUT("heap is initialized with values:")
    for (auto el : vec) 
        std::cout << el.first << ' ' << el.second << std::endl;
    COUT("getting max element:")
    COUT(heap.get_max())
    COUT("extracting max element:")
    COUT(heap.extract_max())
    heap.insert(4, 'd');
    COUT("adding (4, d) element. See max now:")
    COUT(heap.get_max())
    
    std::vector<int> arr({1, 2, 5, 0, 9});
    COUT("testing sort algorithm. Initial array is:")
    PRINT_ARRAY(arr)
    COUT("sorted array is:")
    PRINT_ARRAY(bh_sort(arr))
    return 0;
}