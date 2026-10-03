#include <iostream>
#include <string>

using namespace std;

int main() {
    hash<string> str_hasher;
    hash<int> int_hasher;

    std::cout << str_hasher("hello") << endl;
    std::cout << int_hasher(385248) << endl;
}
