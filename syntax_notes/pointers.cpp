#include <iostream>

// указатели

int main(void) {

    using std::cout;
    using std::endl;

    int a;

    int* a_ptr = &a; // & - взятие адреса, * - разыменование указателя
    int** a_ptr_2 = &a_ptr;

    cout << std::hex << "a - pointer " <<
            sizeof a_ptr << ' ' << a_ptr << endl;
    cout << "pointer that points at a - pointer " <<
            sizeof a_ptr_2 << ' ' << a_ptr_2 << endl;

    cout << std::dec;


    // new и delete

    int *integer_ptr = new int(); // динамическое выделение памяти под int

    cout << "enter an integer: " << endl;
    std::cin >> *integer_ptr;
    cout << *integer_ptr << endl;
    *integer_ptr = 12;
    cout << *integer_ptr << endl;

    delete integer_ptr; // delete для освобождения ресурсов под объект


    // new и динамические массивы

    const short c_arr_size = 5;

    int* arr_ptr = new int[c_arr_size] {1, 2, 3, 4, 5}; // динамическое выделение неизвестной на этап компиляции памяти под массив

    for (int index = 0; index < c_arr_size - 1; ++index) {

        cout << *(arr_ptr + index) << ' ';
    }

    cout << *(arr_ptr + c_arr_size - 1) << endl;

    delete[] arr_ptr; // освобождение ресурсов

    return 0;
}
