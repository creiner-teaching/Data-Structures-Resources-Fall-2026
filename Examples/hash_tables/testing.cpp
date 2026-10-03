#include <iostream>
#include <vector>

using namespace std;

int main() {
 
    vector<int> results;
    for (int i = 0; i < 100000; i++) {
        if (i % 10 == 8) {
            results.push_back(i);
        }
    }

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
