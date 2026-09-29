#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList my_list;
    
    my_list.append("hello");
    my_list.append("how");
    my_list.append("are");

    cout << my_list << endl;
    cout << my_list[1] << endl;
    my_list.remove_index(2);
    cout << my_list << endl;

    return 0;
}
