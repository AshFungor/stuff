#include <iostream>






int main(void) {

    using namespace std;

    const int arr_size = 5;

    int* arr = new int[arr_size] {1, 2, 3, 4, 5};

    int const_arr[arr_size] = {1, 2, 3, 4, 5};

    cout << "iterating through const array: ";
    for (auto init_ptr = const_arr; init_ptr - const_arr < arr_size; ++init_ptr)

        cout << *init_ptr << ' ';



    cout << endl;

    cout << "iterating through non - const array: ";
    for (auto init_ptr = arr ; init_ptr - arr != arr_size ; ++init_ptr )

        cout << *init_ptr << ' ';

    cout << endl;

    int var, another_var;

    cout << "some magic: ";

    var = (another_var = 1, 2); // выражение_1, выражение_2, выражение_3 -> выражение_3

    cout << var << ' ' << another_var << endl;

    auto temp_ptr = arr;

    for (cin >> *arr; (temp_ptr - arr) != arr_size - 1; cin >> *(++temp_ptr))

        ;



    delete[] arr;

    return 0;


}
