#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

int main() {
    int choice, x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        cout << "Result: " << add(x, y);
    else if (choice == 2)
        cout << "Result: " << subtract(x, y);
    else if (choice == 3)
        cout << "Result: " << multiply(x, y);
    else if (choice == 4)
        cout << "Result: " << divide(x, y);
    else
        cout << "Invalid choice";

    return 0;
}
