#include <iostream> 
using namespace std;

int main() {
    int x = 1;
    int *p;

    // make p point to x
    p = &x;

    // deference p to change the value it is
    // pointing to (x)
    *p = 2;

    cout << "x  = " << x << endl;
    cout << "*p = " << *p << endl;
    cout << endl;
    cout << "&x = " << &x << endl;
    cout << "p  = " << p << endl;
    cout << endl;
    cout << "&p = " << &p << endl;

    return 0;
}

