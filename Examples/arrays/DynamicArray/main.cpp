#include <iostream>
#include <stdexcept>
#include "dynamic_array.h"
using namespace std;

int main() {
    dynamic_array a(4);
    a.append(1);
    a.append(1);
    a.append(1);
    a.append(1);
    cout << "array(" << a.cap() << "): " << a << endl;
    a.insert(0, 2);
    a.insert(0, 2);
    a.insert(0, 2);
    a.insert(0, 2);
    cout << "array(" << a.cap() << "): " << a << endl;
    a.insert(4, 3);
    cout << "array(" << a.cap() << "): " << a << endl;

    return 0;
}

