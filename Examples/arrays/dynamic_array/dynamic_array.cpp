#include <iostream>
#include <stdexcept>
#include "dynamic_array.h"
using namespace std;

dynamic_array::dynamic_array(int size) {
    if (size <= 0) {
        throw invalid_argument("size must be at least 1");
    }

    capacity = size;
    data = new int[capacity];
    current_size = 0;
}

dynamic_array::~dynamic_array() {
    delete[] data;
}

int dynamic_array::size() {
    return current_size;
}

int dynamic_array::cap() {
    return capacity;
}

int& dynamic_array::at(int index) {
    if (index < 0 or index >= current_size) {
        throw out_of_range("invalid index");
    }
    return data[index];
}

int& dynamic_array::operator[](int index) {
    return at(index);
}

int dynamic_array::find(int value) {
    for (int i = 0; i < current_size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

void dynamic_array::grow_capacity() {
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

void dynamic_array::insert(int index, int value) {
    if (current_size == capacity) {
        grow_capacity();
    }

    for (int i = current_size-1; i >= index; i--) {
        data[i+1] = data[i];
    }

    data[index] = value;
    current_size++;
}

void dynamic_array::append(int value) {
    insert(current_size, value);
}

void dynamic_array::remove_index(int index) {
    if (index >= current_size) {
        throw out_of_range("invalid index");
    }

    for (int i = index; i < current_size-1; i++) {
        data[i] = data[i+1];
    }

    current_size--;
}

bool dynamic_array::remove_value(int value) {
   int index = find(value);
   if (index == -1) {
       return false;
   }

   remove_index(index);
   return true;
}

ostream& operator<<(ostream& out, dynamic_array& a) {
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ",";
        }
    }
    return out;
}

