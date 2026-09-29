#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    n = 0;
}

LinkedList::~LinkedList() {
    Node* current = head;

    for (int i = 0; i < n; i++) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int LinkedList::size() {
    return n;
}

Node* LinkedList::get_node_at(int index) {
    if (index >= n || index < 0) {
        throw out_of_range("list index out of range");
    }
    // at this point, we know that n is a valid index
    // not an empty list
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

string& LinkedList::at(int index) {
    string& datum = get_node_at(index)->val;
    return datum;
}

string& LinkedList::operator[](int index) {
    return at(index);
}

Node* LinkedList::front() {
    return head;
}

Node* LinkedList::back() {
    // this is O(n) <- bad
    // but if you have a tail pointer of a circular linked list
    //   can be O(1). So you'll improve this for homework
    return get_node_at(n-1);
}

void LinkedList::prepend(string val) {
    Node* new_node = new Node{val}; // dynamic memory!
    new_node->next = head;
    head = new_node;
    n++;
}

void LinkedList::insert(int index, string val) {
    // allows me to use this as append
    if (index > n) {
        throw out_of_range("list index out of range");
    }

    if (index == 0) {
        prepend(val);
        return;
    }

    // if index = 0, should be okay, but we would be getting
    // node at -1, which is why we prepend instead
    // now know index >= 1
    Node* pred = get_node_at(index - 1);
    Node* succ = pred->next; // could be null, but that's okay
    Node* new_node = new Node{val};
    pred->next = new_node;
    new_node->next = succ;
    n++;
}

void LinkedList::append(string val) {
    // again, this is O(n), could be improved if we 
    // had a circular list or were managing a tail pointer
    insert(n, val);
}

void LinkedList::remove_index(int index) {
    // case 1
    if (index < 0 || index >= n) {
        throw out_of_range("list index out of bounds");
    }
    Node* to_trash;
    // not case 1 means head is a real node means head->next is fine
    if (index == 0) {
        // case 2
        to_trash = head;
        head = head->next;
    } else {
        // case 3
        Node* left = get_node_at(index - 1); // safe
        to_trash = left->next; // safe
        left->next = to_trash->next; // safe
    }

    delete to_trash;
    n--;
}

int LinkedList::find(string value) {
    Node* current = head;

    for (int i = 0; i < n; i++) {
        if (current->val == value) {
            return i;
        }
        current = current->next;
    }
    throw domain_error("value not found in list");
}

void LinkedList::remove_value(string value) {
    int search_index = find(value);
    remove_index(search_index);
}

ostream& operator<<(ostream& out, LinkedList& a) {
    out << "[";
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
