#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList my_list;

    cout << my_list << endl;
    my_list.append(205);
    my_list.prepend(999);
    cout << my_list << endl;

    cout << my_list.size() << endl;
    my_list.insert(1, -3543);
    cout << my_list << endl;
    cout << my_list[1] << endl;
    my_list.remove_index(1);
    cout << my_list << endl;
    cout << my_list.size() << endl;
    my_list.remove_value(205);
    cout << my_list << endl;
    return 0;
}
