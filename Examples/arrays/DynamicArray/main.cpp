#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"
using namespace std;

int main() {
    DynamicArray a(4);
    a.append(1);
    a.append(1);
    a.append(1);
    a.append(1);
    cout << a << endl;
    a.insert(0, 2);
    a.insert(0, 2);
    a.insert(0, 2);
    a.insert(0, 2);
    a.insert(4, 3);


    cout << a << endl;

    a.remove_value(1);

    cout << a << endl;

    cout << a[3] << endl;

    a[3] = 5;

    cout << a << endl;

    cout << a.find(5) << endl;

    return 0;
}

