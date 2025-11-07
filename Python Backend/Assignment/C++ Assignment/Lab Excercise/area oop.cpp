#include <iostream>
using namespace std;

class Rectangle {
public:
    float length, width;

    void input() {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
    }

    float calcArea() {
        return length * width;
    }
};

int main() {
    Rectangle r;
    r.input();
    cout << "Area of Rectangle (OOP): " << r.calcArea() << endl;
    return 0;
}
