#include <iostream>
#include <stdexcept>
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
    Node* current_node = head;
    for (int j = 0; j < index; j++) {
        current_node = current_node->next;
    }
    return current_node;
}

void LinkedList::prepend(string val) {
    Node* new_node = new Node{val}; // Note: dynamic memory!
    new_node->next = head;
    head = new_node;
    n++;
}

void LinkedList::insert(int index, string val) {
    if (index < 0 || index > n) {
        throw out_of_range("list index out of range");
    } 

    if (index == 0) {
        prepend(val);
        return;
    }

    Node* pred = get_node_at(index - 1);
    Node* succ = pred->next;
    Node* new_node = new Node{val}; 

    pred->next = new_node;
    new_node->next = succ;
    n++;
}

void LinkedList::append(string val) {
    insert(n, val);
    // Note: If we were keeping track of a tail node as well as a head,
    //   this would be as simple and efficient as prepend. You'll improve
    //   this for homework, not by adding a tail but rather by making the list
    //   circular, so that head.prev = tail
}

string& LinkedList::at(int index) {
    string& val = get_node_at(index)->val;
    return val;
}

string& LinkedList::operator[](int index) {
    return at(index);
}

Node* LinkedList::front() {
    if (n == 0) {
        throw out_of_range("list is empty.");
    }
    return head;
}

Node* LinkedList::back() {
    if (n == 0) {
        throw out_of_range("list is empty.");
    }
    return get_node_at(n-1);
}

void LinkedList::remove_index(int index) {
    // three cases (each successive case assumes NOT former cases)
    // one: invalid index, just throw exception
    // two: index = 0. In this case, no left node to deal with, 
    //      just reassign head to next and schedule deletion
    // three: index != 0 AND index valid means left node guaranteed exists. 
    //        in this case, our board algorithm works without a hitch.
    if (index < 0 || index >= n) {
        throw out_of_range("list index out of bounds");
    }

    Node* to_trash;
    if (index == 0) {
        to_trash = head;
        head = head->next;
    } else { // at this point, we know the following line won't fail
        Node* left = get_node_at(index - 1);
        to_trash = left->next;
        left->next = to_trash->next;
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

void LinkedList::remove_value(string val) {
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
