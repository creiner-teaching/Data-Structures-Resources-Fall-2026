#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray(int size) {
    if (size <= 0) {
        throw invalid_argument("size must be at least 1");
    }

    capacity = size;
    data = new int[capacity];
    current_size = 0;
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

int DynamicArray::size() {
    return current_size;
}

int& DynamicArray::at(int index) {
    if (index < 0 or index >= current_size) {
        throw out_of_range("invalid index");
    }
    return data[index];
}

int& DynamicArray::operator[](int index) {
    return at(index);
}

int DynamicArray::find(int value) {
    for (int i = 0; i < current_size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    throw domain_error("no matching value found");
}

void DynamicArray::grow_capacity() {
    // keep a pointer to the original array
    int *old = data;

    // allocate a new array that is twice as large
    capacity *= 2;
    data = new int[capacity];
        
    // copy all values over to the new array
    for (int i = 0; i < current_size; i++) {
        data[i] = old[i];
    }

    // don't forget to clean up the old array
    delete[] old;
}

void DynamicArray::insert(int index, int value) {
    if (current_size == capacity) {
        grow_capacity();
    }

    for (int i = current_size-1; i >= index; i--) {
        data[i+1] = data[i];
    }

    data[index] = value;
    current_size++;
}

void DynamicArray::append(int value) {
    insert(current_size, value);
}

void DynamicArray::remove_index(int index) {
    if (index >= current_size) {
        throw out_of_range("invalid index");
    }

    for (int i = index; i < current_size-1; i++) {
        data[i] = data[i+1];
    }

    current_size--;
}

bool DynamicArray::remove_value(int value) {
    try {
        int index = find(value);
        remove_index(index);
        return true;
    } catch (domain_error) {
        return false;
    }
}

ostream& operator<<(ostream& out, DynamicArray& a) {
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ",";
        }
    }
    return out;
}

