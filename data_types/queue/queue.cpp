// template class
// такая структура класса нужна для решения проблемы линкера

#include <vector>
#include <stdexcept>
#include <memory>

#ifndef QUEUE00_H_
#define QUEUE00_H_

// Node структура для представления узла в очереди
template<class T>
struct Node {

private:
    std::shared_ptr<Node<T>> next;
    T value;

public:
    Node(const T& init_val) {
        this->value = init_val;
        this->next = nullptr;
    }
    T get_val() const { return this->value; }
    void set_val(const T& new_val) { this->value = new_val; }
    void set_pointer(std::shared_ptr<Node<T>> next_node) { if (!this->next) this->next = next_node; }
    std::shared_ptr<Node<T>> get_pointer() const { return this->next; }

};


// непосредственно класс очереди
template<class T>
class Queue {
    std::shared_ptr<Node<T>> last = nullptr;
    std::shared_ptr<Node<T>> forth = nullptr;
    int q_len;

public:
    Queue(const std::vector<T>& init_arr);
    Queue();
    T pop();
    T peek();
    int size() const;
    void push(const T& val);
    // ~Queue();

};

// определения членов класса

template<class T>
Queue<T>::Queue(const std::vector<T>& init_arr) {

    q_len = init_arr.size();
    auto iterator = init_arr.begin();
    forth = std::shared_ptr<Node<T>>(new Node<T>(*iterator++));
    for (std::shared_ptr<Node<T>> current = forth; iterator != init_arr.end(); ++iterator) {
        current->set_pointer(std::shared_ptr<Node<T>>(new Node<T>(*iterator)));
        current = current->get_pointer();
        if (iterator == init_arr.end()) {
            last = current;
        }
    }

    // если last равен nullptr в конце 
    // выполнения, то в очереди менее 2-х
    // элементов

}

template <class T>
Queue<T>::Queue() { q_len = 0; }

template <class T>
int Queue<T>::size() const { return q_len; }

template<class T>
T Queue<T>::pop() {
    --q_len;
    if (forth) {
        std::shared_ptr<Node<T>> to_remove = forth;
        forth = forth->get_pointer();
        return to_remove->get_val();
    }
    else { throw std::runtime_error("cannot remove front element of an empty queue"); }

}

template<class T>
T Queue<T>::peek() {
    if (forth) { return forth->get_val(); }
    else { throw std::runtime_error("cannot peek at front element of an empty queue"); }
}

template<class T>
void Queue<T>::push(const T& val) {
    ++q_len;
    if (last) {
        // есть последний элемент - все просто
        last->set_pointer(std::shared_ptr<Node<T>>(new Node<T>(val)));
        last = last->get_pointer();
    }
    else if (forth) {
        // в очереди только один элемент
        forth->set_pointer(std::shared_ptr<Node<T>>(new Node<T>(val)));
        last = forth->get_pointer();
        // теперь два
    }
    else {
        // очередь пуста
        forth = std::shared_ptr<Node<T>>(new Node<T>(val));
    }
}

// деструктор не нужен благодаря умным указателям

// template<class T>
// Queue<T>::~Queue() {
//     std::shared_ptr<Node<T>> current = forth, temp;
//     while (current) {
//         temp = current->get_pointer();
//         current.reset();
//         current = temp;
//     }
// }


#endif

