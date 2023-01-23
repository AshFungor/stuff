#include <iostream>
#include <cmath>

// указатели на функции

using std::cout;

double f(double base, double power);
double* g(double, double);


int main(void) {

    double (*func)(double, double); // func - указатель на функцию сигнатуры double FUNC(double, double)
    double* (*ptr_ret_func)(double, double); // ptr_ret_func - double* FUNC(double, double)

    func = f;
    ptr_ret_func = g;

    // вызов по указателю
    double* to_del;

    cout << func(2, 3) << ' ' << (*func)(2, 3) << std::endl; // func() и (*func)() - одно и то же
    cout << std::hex << (to_del = ptr_ret_func(2, 2)) << std::endl;

    delete to_del;

    


    return 0;
}


double f(double base, double power) {

    if (base >= 0)
        return pow(base, power);
    
    return -1;
}

double* g(double x, double y) {  

    double* res = new double {x + y};

    return res;
}
