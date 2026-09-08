#include <iostream>

using namespace std;

int main() {

    int x = 5;
    int* p = &x;  // pointer to x

    cout << p << endl;  // prints memory address
    cout << *p << endl; // dereferences the pointer, prints the thing

    return 0;
}
