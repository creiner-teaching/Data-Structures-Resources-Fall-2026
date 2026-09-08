#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* data;
    int capacity;
    int current_size;

    void grow_capacity();

public:
    DynamicArray(int size);
    ~DynamicArray();

    int size();

    int& at(int index);
    int& operator[](int index);
    int find(int value); // finds the first index containing value

    void insert(int index, int value);
    void append(int value);

    void remove_index(int index); 
    bool remove_value(int value); // removes first instance of value
};

ostream& operator<<(ostream& out, DynamicArray& a);

