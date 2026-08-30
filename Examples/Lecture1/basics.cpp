#include <iostream>  // needed for cin/cout
#include <string>    // needed for stof()
#include <stdexcept> // needed for runtime_error
using namespace std;

void print_array(string name, float a[], int size) {
    if (size < 0) {
        throw runtime_error("bad array size");
    }
    for (int i = 0; i < size; i++) {
        cout << name << "[" << i << "]=" << a[i] << endl;
    }
}

int main() {
    int capacity = 8, size = 0;
    float nums[capacity];
    cout << "Enter up to " << capacity << " numbers, or quit to stop:" << endl;

    while (size < 8) {
        string input_str;
        cin >> input_str;
        if (input_str == "quit") {
            break;
        }

        float input_num;
        try {
            input_num = stof(input_str);
        } catch (invalid_argument& e) {
            cout << "That's not a number." << endl;
            continue;
        }
        nums[size] = input_num;
        size++;
    }

    print_array("nums", nums, size);

    return 0;
}
