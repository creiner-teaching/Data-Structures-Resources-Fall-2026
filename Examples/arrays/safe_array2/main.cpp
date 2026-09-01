#include <iostream>
#include <stdexcept>
#include "safe_array.h"
using namespace std;

int main() {
    safe_array a(8);
    a.append(5);
    a.append(2);
    a.append(4);
    a.append(1);
    a.append(9);
    cout << "array: " << a << endl;

    a.insert(3, 7);
    cout << "array: " << a << endl;

    a.remove_index(0);
    cout << "array: " << a << endl;

    a.remove_value(4);
    cout << "array: " << a << endl;
    return 0;
}

