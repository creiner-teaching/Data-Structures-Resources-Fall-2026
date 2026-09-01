using namespace std;

class safe_array {
private:
    int *data;
    int capacity;
    int current_size;

public:
    safe_array(int size);
    ~safe_array();

    int size();
    int cap();

    int& at(int index);
    int& operator[](int index);
    void add(int value);
};

ostream& operator<<(ostream& out, safe_array& a);

