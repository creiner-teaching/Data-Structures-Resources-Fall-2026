#include <iostream>
using namespace std;

class shape {
// protected members can be used in the class and any derived classes
protected:
    string name;

public:
    shape(string n) {
        name = n;
    }

    string get_name() {
        return name;
    }

    // this is pure virtual function, with no implementation provided
    // in the base class; derived classes must provide it themselves
    virtual float area() = 0;
};

ostream& operator<<(ostream& out, shape& s) {
    out << s.get_name() << " has area " << s.area();
    return out;
}

// this says that the rectangle class inherits from the shape class
class rectangle : public shape {
protected:
    float length, width;

public:
    rectangle(string n, float l, float w) : shape(n) {
        length = l;
        width = w;
    }

    // the override keyword tells C++ that this is the same as the
    // override function in the base class
    float area() override {
        return length * width;
    }
};

class circle : public shape {
protected:
    float radius;

public:
    circle(string n, float r) : shape(n) {
        radius = r;
    }

    float area() override {
        return 3.14159265 * radius * radius;
    }
};

int main() {
    int num_shapes = 2;
    shape *shapes[num_shapes];
    shapes[0] = new rectangle("r1", 4, 5);
    shapes[1] = new circle("c1", 1);
    for (int i = 0; i < num_shapes; i++) {
        // shapes[0] is a rectangle, and shapes[1] is a circle
        // but they are both also shape objects
        cout << *shapes[i] << endl;
    }
    return 0;
}

