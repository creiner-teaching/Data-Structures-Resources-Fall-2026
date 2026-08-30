#include <iostream> 
using namespace std;

void a_function(int &ref_param, int val_param) {
    int local_var = 10;
    cout << "&val_param = " << &val_param << endl;
    cout << "&local_var = " << &local_var << endl;
    cout << "&ref_param = " << &ref_param << endl;
}

int main() {
    int main_var2 = 15;
    int main_var1 = 20;
    a_function(main_var1, main_var2);
    cout << "&main_var1 = " << &main_var1 << endl;
    cout << "&main_var2 = " << &main_var2 << endl;
    return 0;
}

