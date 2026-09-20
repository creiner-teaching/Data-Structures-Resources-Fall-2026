#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Node {
    int val;
    Node* next = nullptr;
};

class LinkedList {
private:
    Node* first;
    int length;
    Node* get_node_at(int index);

public:
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList& other) = delete;
    LinkedList& operator=(LinkedList& other) = delete;
    
    int size();
    int& at(int index);
    int& operator[](int index);
    void prepend(int val);
    void append(int val);
    void insert(int index, int val);
    int find(int val);
    void remove_index(int index);
    void remove_value(int val);
};

ostream& operator<<(ostream& out, LinkedList& list);
