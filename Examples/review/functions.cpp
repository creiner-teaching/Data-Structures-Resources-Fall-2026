#include <iostream> 
#include <string> 
using namespace std;

int get_integer(string value_name) {
    string tmp;
    cout << "Enter " << value_name << ": ";
    cin >> tmp;
    try {
        return stoi(tmp);    
    } catch (invalid_argument& e) {
        cout << "That's not an integer!" << endl;
        exit(1);
    }
}

bool divmod(int x, int y, int& div, int& mod) {
    if (y == 0) {
        return false;
    }

    div = x / y;
    mod = x % y;
    return true;
}

int main() {
    int a = get_integer("a");
    int b = get_integer("b");

    int whole, remainder;
    if (!divmod(a, b, whole, remainder)) {
        cout << "Can't divide by zero!" << endl;
        return 1;
    }

    cout << a << "/" << b << "=" << whole << endl;
    cout << a << "%" << b << "=" << remainder << endl;

    return 0;
}
