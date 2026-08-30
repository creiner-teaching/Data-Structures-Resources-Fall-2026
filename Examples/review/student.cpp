#include <iostream> 
#include <string> 
#include <iomanip> 
#include <stdexcept> 
using namespace std;

class student {
// private members are only accessible within member functions
private:
    string name;
    float *grades;
    int num_grades;
    int current_grade;

// public members can be used in any code
public:
    // constructor to create a new student object
    student(string &student_name, int max_num_grades) {
        name = student_name;
        num_grades = max_num_grades;
        grades = new float[num_grades];
        current_grade = 0;
    }

    // destructor to clean up any memory allocated to this object
    ~student() {
        delete[] grades;
    }

    string get_name() {
        return name;
    }

    void add_grade(float new_grade) {
        if (current_grade == num_grades) {
            throw out_of_range("all grades already given");
        }

        grades[current_grade] = new_grade;
        current_grade++;
    }

    float get_average() {
        if (current_grade == 0) {
            throw out_of_range("no grades given");
        }

        float sum = 0;
        for (int i = 0; i < current_grade; i++) {
            sum += grades[i];
        }
        return sum / current_grade;
    }
};

// operator overloading << to work with student objects
ostream& operator<<(ostream& out, student& s) {
    out << fixed << setprecision(2);
    out << s.get_name() << ": " << s.get_average();
    return out;
}

int main() {
    string name1 = "alice";
    student s1(name1, 3);
    s1.add_grade(88.0);
    s1.add_grade(94.0);
    s1.add_grade(98.0);
    cout << s1 << endl;

    string name2 = "beth";
    student *s2 = new student(name2, 2);
    // -> is used to dereference a pointer to an object
    // and access one of its members
    s2->add_grade(94.5);
    s2->add_grade(86.2);
    cout << *s2 << endl;
    delete s2;
    return 0;
}

