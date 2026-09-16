#include <iostream>
#pragma once

using namespace std;

class ArrayList {
private:
    int current_size;
    int capacity;
    int* elements; 

    void grow_capacity();

public:
    ArrayList(int desired_capacity = 10);
    ~ArrayList();
    ArrayList(const ArrayList&) = delete;
    ArrayList& operator=(const ArrayList&) = delete;
    
    int& at(int index);
    int& operator[](int index);
    int size();
    int cap();
    void append(int value);
    void insert(int index, int value);
    int find(int value);
    void remove_value(int value);
    void remove_index(int index);
};

ostream& operator<<(ostream& out, ArrayList& list);
