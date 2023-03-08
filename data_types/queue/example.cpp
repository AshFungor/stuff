#include <iostream>
#include <ostream>
#include <vector>
#include "queue.cpp"

#define COUT(str) std::cout << str << std::endl;

int main(void) {

    Queue<int> q{};
    COUT("initializing empty queue...")
    COUT("pushing value 2 in a queue...")
    q.push(2);
    std::cout << "size of queue is " << q.size() << ", front element is " << q.peek() << std::endl;
    COUT("pushing value 3 in a queue...")
    q.push(3);
    std::cout << "size of queue is " << q.size() << ", front element is " << q.peek() << std::endl;
    COUT("removing all elements from queue:")
    std::cout << q.pop() << ' ' << q.pop() << std::endl;

    COUT("initializing new queue (q2) with a vector instance...")
    std::vector<int> vec{3, 3, 3};
    std::cout << "vector is ";
    for (auto element : vec) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    Queue<int> q2{vec};
    COUT("removing all elements from new queue:")
    std::cout << q2.pop() << ' ' << q2.pop() << ' ' << q2.pop() << std::endl;
    COUT("pushing value 2 in a queue...")
    q2.push(2);
    std::cout << "q2 size is " << q2.size() << std::endl;
    return 0;
}