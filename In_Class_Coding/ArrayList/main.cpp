#include <iostream>
#include <vector>
#include "ArrayList.h"

using namespace std;

int main() {
    ArrayList<string> my_list;
    
    my_list.append("hello");
    my_list.append("how");
    my_list.append("are");

    cout << my_list << endl;

    return 0;
}
