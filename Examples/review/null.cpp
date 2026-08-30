#include <iostream> 
using namespace std;

void print_record(int value, string *name) {
    if (name != NULL) {
        cout << *name << "=";
    }
    cout << value << endl;
}

int main() {
    int x = 42;
    print_record(x, NULL);

    int y = 43;
    string name = "zaphod";
    print_record(y, &name);

    return 0;
}

