#include <iostream>
using namespace std;

class Person {
public:
    string name;
    void getName() {
        cin >> name;
    }
};

class Student : public Person {
public:
    int roll;
    void getData() {
        getName();
        cin >> roll;
    }
    void show() {
        cout << "Student: " << name << " " << roll << endl;
    }
};

class Teacher : public Person {
public:
    float salary;
    void getDataT() {
        getName();
        cin >> salary;
    }
    void showT() {
        cout << "Teacher: " << name << " " << salary << endl;
    }
};

int main() {
    Student s;
    Teacher t;

    s.getData();
    s.show();

    t.getDataT();
    t.showT();

    return 0;
}
