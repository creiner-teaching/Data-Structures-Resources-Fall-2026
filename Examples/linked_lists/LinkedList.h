#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Node {
    string val;
    Node* next = nullptr;
};

class LinkedList {
private:
    Node* head;
    int n;
    Node* get_node_at(int index);

public:
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList& other) = delete;
    LinkedList& operator=(LinkedList& other) = delete;
    
    int size();
    string& at(int index);
    string& operator[](int index);
    Node* front();
    Node* back();
    void prepend(string val);
    void append(string val);
    void insert(int index, string val);
    int find(string val);
    void remove_index(int index);
    void remove_value(string val);
};

ostream& operator<<(ostream& out, LinkedList& list);
