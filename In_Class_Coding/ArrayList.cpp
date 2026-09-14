#include <iostream>

using namespace std;

// Array implementation of the List ADT 
// for simplicity, it contains integers specifically
class ArrayList {
private:
    int current_size;
    int capacity;
    int* elements; // the actual array
    
public:
    // constructor
    ArrayList(int desired_capacity = 10) {
        capacity = desired_capacity;
        elements = new int[capacity];
        current_size = 0;
    }

    ~ArrayList() {
        delete[] elements;
    }

    int& at(int index) {
        if (index < 0 || index > current_size-1) {
            throw invalid_argument("list index out of range");
        }
        return elements[index];
    }

    int& operator[](int index) {
        return at(index);
    }

    int size() {
        return current_size; 
    }

    int cap() {
        return capacity;
    }

    void append(int value) {
        if (current_size == capacity) {
            throw out_of_range("list is at capacity");
        }
        elements[current_size] = value;
        current_size++;
    }

    // void insert(int index, int value) {}
    // int find(int value) {}
    // void remove_value(int value);
    // void remove_index(int index);
};

// problem was ArrayList had to be passed by reference
ostream& operator<<(ostream& out, ArrayList list) {
    out << "[";
    for (int i = 0; i < list.size(); i++) {
        out << list[i];
    }
    out << "]";
    return out;
}

int main() {
    ArrayList test(20);

    test.append(1);
    cout << test << endl;
    test.append(2);
    cout << test << endl;

    cout << test.size() << endl;
    cout << test.cap() << endl;

    return 0;
}
