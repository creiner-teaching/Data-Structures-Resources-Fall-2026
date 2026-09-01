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
    int find(int value); // finds the first index containing value

    void insert(int index, int value);
    void append(int value);

    void remove_index(int index); 
    bool remove_value(int value); // removes first instance of value
};

ostream& operator<<(ostream& out, safe_array& a);

