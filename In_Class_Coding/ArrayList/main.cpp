#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
    ArrayList my_list;
    
    my_list.append(1);
    my_list.append(2);
    my_list.append(3);

    cout << my_list << endl;
    return 0;
}
