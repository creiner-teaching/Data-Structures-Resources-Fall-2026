#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
ArrayList<T>::ArrayList(int size) {
    if (size <= 0) {
        throw invalid_argument("size must be at least 1");
    }

    capacity = size;
    data = new T[capacity];
    current_size = 0;
}

template<typename T>
ArrayList<T>::ArrayList() {
    capacity = 10;
    data = new T[capacity];
    current_size = 0;
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

template<typename T>
int ArrayList<T>::size() {
    return current_size;
}

template<typename T>
T& ArrayList<T>::at(int index) {
    if (index < 0 or index >= current_size) {
        throw out_of_range("invalid index");
    }
    return data[index];
}

template<typename T>
T& ArrayList<T>::operator[](int index) {
    return at(index);
}

template<typename T>
int ArrayList<T>::find(T value) {
    for (int i = 0; i < current_size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    throw domain_error("no matching value found");
}

template<typename T>
void ArrayList<T>::grow_capacity() {
    // keep a pointer to the original array
    T* old = data;

    // allocate a new array that is twice as large
    capacity *= 2;
    data = new T[capacity];
        
    // copy all values over to the new array
    for (int i = 0; i < current_size; i++) {
        data[i] = old[i];
    }

    // don't forget to clean up the old array
    delete[] old;
}

template<typename T>
void ArrayList<T>::insert(int index, T value) {
    if (current_size == capacity) {
        grow_capacity();
    }

    for (int i = current_size-1; i >= index; i--) {
        data[i+1] = data[i];
    }

    data[index] = value;
    current_size++;
}

template<typename T>
void ArrayList<T>::append(T value) {
    insert(current_size, value);
}

template<typename T>
void ArrayList<T>::remove_index(int index) {
    if (index >= current_size) {
        throw out_of_range("invalid index");
    }

    for (int i = index; i < current_size-1; i++) {
        data[i] = data[i+1];
    }

    current_size--;
}

template<typename T>
bool ArrayList<T>::remove_value(T value) {
    try {
        int index = find(value);
        remove_index(index);
        return true;
    } catch (domain_error) {
        return false;
    }
}

template<typename T>
ostream& operator<<(ostream& out, ArrayList<T>& a) {
    out << "[";
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ",";
        }
    }
    out << "]";
    return out;
}
