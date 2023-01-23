#include <iostream>

// операторы ветвления: ? и switch

int main(void){

    using namespace std;

    // оператор ?

    int example = {};

    for (short time = {}; time < 3; ++time) {
        cin >> example;
        cout << ((example == 0) ? "zero" : "non-zero") << endl; // оператор ?: (выражение, приводимое к bool) ? операнд_1 : операнд_2

        // ? позволяет упростить if else (? еще называется тернарным т.к. он один составляется из трех операндов и единственный)
    }

    // switch

    /*

    switch (целочисленное выражение, например int, bool, enum, char){

        case метка_1: операторы;
        case метка_2: операторы;
        default:
            операторы;
        default выполняется после всех меток если контроль не быль передан за пределы switch
    }



    */

   switch (example) {

       case 0:
       cout << "switch: zero" << endl;
       break;
       default:
       cout << "switch: non-zero" << endl;
   }


        

        
    

    return 0;
}