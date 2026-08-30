#include <iostream>
using namespace std;

int *fill_array(int size) {
    int *a = new int[size];
    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    return a;
}

void print_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i];
        if (i != size-1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        cout << "n must be positive." << endl;
        return 1;
    }

    int *data = fill_array(n);
    print_array(data, n);

    delete[] data;
    return 0;
}

