#include <iostream>
#include <stdexcept>
#include "safe_array.h"
using namespace std;

safe_array::safe_array(int size) {
    if (size <= 0) {
        throw invalid_argument("size must be at least 1");
    }

    capacity = size;
    data = new int[capacity];
    current_size = 0;
}

safe_array::~safe_array() {
    delete[] data;
}

int safe_array::size() {
    return current_size;
}

int safe_array::cap() {
    return capacity;
}

int& safe_array::at(int index) {
    if (index < 0 or index >= current_size) {
        throw out_of_range("invalid index");
    }
    return data[index];
}

int& safe_array::operator[](int index) {
    return at(index);
}

void safe_array::add(int value) {
    if (current_size == capacity) {
        throw out_of_range("array is full");
    }
    data[current_size] = value;
    current_size++;
}

ostream& operator<<(ostream& out, safe_array& a) {
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ",";
        }
    }
    return out;
}

