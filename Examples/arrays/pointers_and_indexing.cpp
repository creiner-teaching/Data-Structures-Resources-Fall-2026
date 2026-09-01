#include <iostream>
using namespace std;

int main() {
    int a[5] = {1,2,3,4,5};

    cout << a[1] << endl;
    // same thing
    int* p = &(a[0]);
    cout << *(p+1) << endl;

    // indifferent
    cout << a[6] << endl;

    return 0;
}
