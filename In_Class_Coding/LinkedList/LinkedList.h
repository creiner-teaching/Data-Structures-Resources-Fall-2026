#include <iostream>
#include <string>

using namespace std;

struct Node {
    string val;
    Node* next = nullptr;
};

class LinkedList {
private:
    Node* head;
    int n; // size
    
    Node* get_node_at(int index);

public:
    LinkedList();
    ~LinkedList();

    int size();

    string& at(int index);
    string& operator[](int index);
    int find(string value); 

    void insert(int index, string value);
    void prepend(string value);
    void append(string value);

    Node* front(); // returns the head node
    Node* back(); // returns the tail node

    void remove_index(int index); 
    void remove_value(string value); 
};

ostream& operator<<(ostream& out, LinkedList& a);
