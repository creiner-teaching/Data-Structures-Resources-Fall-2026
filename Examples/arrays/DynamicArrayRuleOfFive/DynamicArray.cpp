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

DynamicArray::DynamicArray(DynamicArray& other) {
    capacity = other.capacity;
    current_size = 0;
    data = new int[capacity];
    for (int i = 0; i < other.size(); i++) {
        append(other[i]);
    }
}

DynamicArray::DynamicArray(DynamicArray&& other) {
    data = other.data;
    capacity = other.capacity;
    current_size = other.current_size;

    other.data = nullptr;
    other.capacity = 0;
    other.current_size = 0;
}

/**
* @brief called when we do something like
*           DynamicArray b;
*           b = a; // b exists already.
*       This calls b.operator=(a); <- need to replace b with a.
*       Thus, in the function body, this refers to b. 
* @return should always just be a reference to `this`. 
*       It is only used when we do something ridiculous like a = b = c
*       which would act like a = (b = c). Here, b = c needs to return the copy,
*       for use in the next copy-assignment call.
 */
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    // Try to answer this for yourself: why do we need this?
    if (this == &other) {
        return *this;
    }

    delete[] data;

    capacity = other.capacity;
    current_size = 0;
    data = new int[capacity];

    for (int i = 0; i < other.size(); i++) {
        append(other[i]);
    }

    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    data = other.data;
    capacity = other.capacity;
    current_size = other.current_size;

    other.data = nullptr;
    other.capacity = 0;
    other.current_size = 0;

    return *this;
}

int DynamicArray::size() const {
    return current_size;
}

int& DynamicArray::at(int index) {
    if (index < 0 or index >= current_size) {
        throw out_of_range("invalid index");
    }
    return data[index];
}

int DynamicArray::at(int index) const {
    if (index < 0 or index >= current_size) {
        throw out_of_range("invalid index");
    }
    return data[index];
}

int& DynamicArray::operator[](int index) {
    return at(index);
}

int DynamicArray::operator[](int index) const {
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
    int *old = data;

    capacity *= 2;
    data = new int[capacity];
        
    for (int i = 0; i < current_size; i++) {
        data[i] = old[i];
    }

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

