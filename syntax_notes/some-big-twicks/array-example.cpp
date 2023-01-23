

#ifndef __ARRAY_EXAMPLE // если файл еще не подключен
#define __ARRAY_EXAMPLE // флаг включения устанавливается

static int number = 1;

struct custom_array {
    int* arr;
    int len;

};


custom_array build(int len, bool set_to_zero = false) {

    custom_array arr = {new int[len], len};

    if (set_to_zero)
        for (int i = 0; i < len; ++i)
            arr.arr[i] = 0;

    return arr;

}


#endif
