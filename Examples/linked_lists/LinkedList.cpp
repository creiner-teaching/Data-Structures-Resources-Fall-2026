#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    first = nullptr;
    length = 0;
}

LinkedList::~LinkedList() {
    Node* current = first;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int LinkedList::size() {
    return length;
}

Node* LinkedList::get_node_at(int index) {
    if (index > length - 1) {
        throw out_of_range("list index out of range");
    }
    int current_index = 0;
    Node* current_node = first;
    while (current_index != index) {
        current_node = current_node->next;
        current_index++;
    }
    return current_node;
}

void LinkedList::prepend(int val) {
    Node* new_node = new Node{val}; // Note: dynamic memory!
    new_node->next = first;
    first = new_node;
    length++;
}

void LinkedList::insert(int index, int val) {
    Node* pred;
    if (index == 0 || length == 0) {
        prepend(val);
        return;
    } else {
        pred = get_node_at(index - 1);
    }
    Node* succ = pred->next;
    Node* new_node = new Node{val}; 
    pred->next = new_node;
    new_node->next = succ;
    length++;
}

void LinkedList::append(int val) {
    insert(length - 1, val);
    // Note: If we were keeping track of a last node as well as a first,
    //   this would be as simple and efficient as prepend. You'll improve
    //   this for homework.
}

int& LinkedList::at(int index) {
    int& val = get_node_at(index)->val;
    return val;
}

int& LinkedList::operator[](int index) {
    return at(index);
}

void LinkedList::remove_index(int index) {
    Node* left;
    Node* to_trash;
if (length == 0) {
        throw out_of_range("list index out of bounds");
    }
if (index == 0) {
        left = nullptr;
        to_trash = first;
    } else {
        left = get_node_at(index - 1);
        to_trash = left->next;
    }
    if (to_trash == nullptr) {
        throw out_of_range("list index out of bounds");
    }
    Node* right = to_trash->next;
    left->next = right;
    delete to_trash;
    length--;
}

int LinkedList::find(int value) {
    for (int i = 0; i < length; i++) {
        if (at(i) == value) {
            return i;
        }
    }
    throw domain_error("value not found in list");
}

void LinkedList::remove_value(int val) {
    int search_index = find(val);
    remove_index(search_index);
}

ostream& operator<<(ostream& out, LinkedList& list) {
    out << "[";
    for (int i = 0; i < list.size(); i++) {
        out << list[i];
        if (i < list.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
