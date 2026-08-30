#include <iostream>
using namespace std;

int main() {
    cout << "char:   " << sizeof(char) << endl;
    cout << "short:  " << sizeof(short) << endl;
    cout << "int:    " << sizeof(int) << endl;
    cout << "long:   " << sizeof(long) << endl;
    cout << "float:  " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "int[10]:" << sizeof(int[10]) << endl;
    return 0;
}
