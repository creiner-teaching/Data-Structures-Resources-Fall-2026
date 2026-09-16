#include <iostream>
#include "ArrayList.h"

using namespace std;

void ArrayList::grow_capacity() {
    // keep a pointer to the original array
    int *old = elements;

    // allocate a new array that is twice as large
    capacity *= 2;
    elements = new int[capacity];
        
    // copy all values over to the new array
    for (int i = 0; i < current_size; i++) {
        elements[i] = old[i];
    }

    // don't forget to clean up the old array
    delete[] old;
}

ArrayList::ArrayList(int desired_capacity) {
    capacity = desired_capacity;
    elements = new int[capacity];
    current_size = 0;
}

ArrayList::~ArrayList() {
    delete[] elements;
}

int& ArrayList::at(int index) {
    if (index < 0 || index > current_size-1) {
        throw invalid_argument("list index out of range");
    }
    return elements[index];
}

int& ArrayList::operator[](int index) {
    return at(index);
}

int ArrayList::size() {
    return current_size; 
}

int ArrayList::cap() {
    return capacity;
}

void ArrayList::append(int value) {
    if (current_size == capacity) {
        grow_capacity();
    }
    elements[current_size] = value;
    current_size++;
}

void ArrayList::insert(int index, int value) {
    if (current_size == capacity) {
        grow_capacity();
    }
    // SHOULD BE > CURRENT_SIZE (otherwise get an exception with insert(0, val))
    if (index < 0 || index >= current_size) {
        throw out_of_range("list index out of range.");
    }
    // move everything over one from end down to index
    // SHOULD BE >=
    for (int i = current_size-1; i > index; i--) {
        elements[i+1] = elements[i];
    }
    // set the value at index
    elements[index] = value;
    current_size++;
}

int ArrayList::find(int value) {
    for (int i = 0; i < current_size; i++) {
        if (elements[i] == value) {
            return i;
        }
    }
    throw domain_error("value not found.");
}

void ArrayList::remove_index(int index) {
    if (index < 0 || index >= current_size) {
        throw out_of_range("list index out of range.");
    }
    // NOT NEEDED
    if (index == current_size-1) {
        current_size--;
        return;
    }
    // SHOULD BE i < current_size - 1
    for (int i = index; i < current_size; i++) {
        elements[i] = elements[i+1];
    }
    current_size--;
}

void ArrayList::remove_value(int value) {
    int index = find(value);
    remove_index(index);
}


// problem was ArrayList had to be passed by reference
ostream& operator<<(ostream& out, ArrayList& list) {
    out << "[";
    for (int i = 0; i < list.size(); i++) {
        out << list[i];
        if (i < list.size()-1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

// operator<< called when I do cout << my_list
