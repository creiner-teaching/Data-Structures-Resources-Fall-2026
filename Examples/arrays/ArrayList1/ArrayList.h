using namespace std;

class ArrayList {
private:
    int *data;
    int capacity;
    int current_size;

public:
    ArrayList(int size);
    ~ArrayList();

    int size();
    int cap();

    int& at(int index);
    int& operator[](int index);
    void add(int value);
};

ostream& operator<<(ostream& out, ArrayList& a);

