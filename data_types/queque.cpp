#include <iostream>
#include <vector>

// Node структура для представления узла в очереди
template<typename T>
struct Node {

private:

    Node* prev;
    T value;

public:

    Node(T &init_val) {
        this->value = init_val;
        this->prev = nullptr;
    }

    auto get_val() {
        return this->value;
    }

    void set_val(T &new_val) {
        this->value = new_val;
    }

    void set_pointer(Node* next_node) {
        if (!this->prev) this->prev = next_node;
    }

    Node* get_pointer() {
        return this->prev;
    }

};

// непосредственно класс очереди
template<typename T>
class Queque {

private:

    Node<T>* last;
    Node<T>* forth;
    int q_len;

public:

    Queque(const std::vector<T>* init_arr = nullptr) {
        if (init_arr) {
            // последовательное заполнение очереди массивом
            std::vector<T> vec = *init_arr;
            this->forth = new Node<T>(vec[0]);
            this->last = forth;
            for (auto iter = vec.begin() + 1; iter != vec.end(); ++iter) {
                this->last->set_pointer(new Node<T>(*iter));
                this->last = this->last->get_pointer();
            }
            this->q_len = vec.size();
            return;
        }
        this->last = nullptr;
        this->forth = nullptr;
        this->q_len = 0;
    }

    T cut() {
        Node<T>* rm_el = this->forth;
        this->forth = this->forth->get_pointer();
        T ret_val = rm_el->get_val();
        delete rm_el;
        --(this->q_len);
        return ret_val;
    }

    void add(T val) {
        this->last->set_pointer(new Node<T>(val));
        this->last = this->last->get_val();
        ++(this->q_len);
    }

    ~Queque() {
        while (forth) {
            Node<T>* rm_el = forth;
            forth = forth->get_pointer();
            delete rm_el;
        }
    }

};


int main(void) {
    std::vector<int> vec{1, 2, 3};
    Queque<int> _q{&vec};
    int len = vec.size();
    while (len--) {
        std::cout << _q.cut();
    }
}