#include <iostream>
using namespace std;

class Person {
public:
    string name;
};

class Student : public Person {
public:
    int roll;

    void getData() {
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> roll;
    }

    void display() {
        cout << "Student Name: " << name << ", Roll No: " << roll << endl;
    }
};

class Teacher : public Person {
public:
    void getData() {
        cout << "Enter Teacher Name: ";
        cin >> name;
    }

    void display() {
        cout << "Teacher Name: " << name << endl;
    }
};

int main() {
    Student s;
    Teacher t;

    s.getData();
    t.getData();

    cout << "\n---Output Is---\n";
    s.display();
    t.display();

    return 0;
}
