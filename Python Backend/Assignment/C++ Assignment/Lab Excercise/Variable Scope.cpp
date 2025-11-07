#include <iostream>
using namespace std;

int x = 10;

void display() {
    int y = 20;
    cout << "Inside function - x: " << x << endl;
    cout << "Inside function - y: " << y << endl;
}

int main() {
    int y = 30;
    cout << "Inside main - x: " << x << endl;
    cout << "Inside main - y: " << y << endl;

    display();

    return 0;
}
