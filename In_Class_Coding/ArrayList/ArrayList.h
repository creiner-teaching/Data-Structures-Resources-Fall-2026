#pragma once
#include <iostream>

using namespace std;

template<typename T>
class ArrayList {
private:
    T* data;
    int capacity;
    int current_size;

    void grow_capacity();

public:
    ArrayList(int size);
    ~ArrayList();

    int size();

    T& at(int index);
    T& operator[](int index);
    int find(T value); // finds the first index containing value

    void insert(int index, T value);
    void append(T value);

    void remove_index(int index); 
    bool remove_value(T value); // removes first instance of value
};

template<typename T>
ostream& operator<<(ostream& out, ArrayList<T>& a);


#include "ArrayList.tpp"
