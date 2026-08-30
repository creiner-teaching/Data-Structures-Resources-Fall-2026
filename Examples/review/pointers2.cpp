#include <iostream> 
using namespace std;

void a_function(int &ref_param, int *ptr_param) {
    cout << "&ref_param = " << &ref_param << endl;
    cout << "&ptr_param = " << &ptr_param << endl;

    ref_param++;
    (*ptr_param)++;
}

int main() {
    int main_var2 = 15;
    int main_var1 = 20;
    a_function(main_var1, &main_var2);
    cout << "&main_var1 = " << &main_var1 << endl;
    cout << "&main_var2 = " << &main_var2 << endl;
    cout << endl;
    cout << "main_var1 = " << main_var1 << endl;
    cout << "main_var2 = " << main_var2 << endl;

    return 0;
}

