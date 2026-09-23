#include <iostream>
#include <vector>
#include "ArrayList.h"

using namespace std;

int main() {
    ArrayList<int> my_list;
    
    my_list.append(1);
    my_list.append(2);
    my_list.append(3);

    for (int val : my_list) {
        cout << val << endl;
    }

    return 0;
}
