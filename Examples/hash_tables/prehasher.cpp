#include <iostream>

using namespace std;

int bad_prehash(string s) {
    int out = 0;
    for (char c : s) {
        out += static_cast<int>(c);
    }
    
    return out;
}

int main() {
    
    cout << bad_prehash("dog") << endl;

    return 0;
}
