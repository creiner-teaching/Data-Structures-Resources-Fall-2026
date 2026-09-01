#include <iostream>
#include <stdexcept>
using namespace std;

class safe_array {
private:
    int *data;
    int capacity;
    int current_size;

public:
    safe_array(int size) {
        if (size <= 0) {
            throw invalid_argument("size must be at least 1");
        }

        capacity = size;
        data = new int[capacity];
        current_size = 0;
    }

    ~safe_array() {
        delete[] data;
    }

    int size() {
        return current_size;
    }

    int cap() {
        return capacity;
    }

    int& at(int index) {
        if (index < 0 or index >= current_size) {
            throw out_of_range("invalid index");
        }
        return data[index];
    }

    int& operator[](int index) {
        return at(index);
    }

    void add(int value) {
        if (current_size == capacity) {
            throw out_of_range("array is full");
        }
        data[current_size] = value;
        current_size++;
    }
};

ostream& operator<<(ostream& out, safe_array& a) {
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ",";
        }
    }
    return out;
}

int main() {
    safe_array a(4);
    cout << "array: " << a << endl;
    a.add(7);
    a.add(-2);
    cout << "array: " << a << endl;

    try {
        cout << a[2] << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    a[1] = 4;
    cout << "array: " << a << endl;
    return 0;
}

