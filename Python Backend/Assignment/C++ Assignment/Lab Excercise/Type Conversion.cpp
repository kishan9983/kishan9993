#include <iostream>
using namespace std;

int main() {
    int a = 10;
    float b = a;

    float x = 5.75;
    int y = (int)x;

    cout << "Implicit Conversion (int to float): " << b << endl;
    cout << "Explicit Conversion (float to int): " << y << endl;

    return 0;
}
