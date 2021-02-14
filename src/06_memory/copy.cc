#include <iostream>

void ChangeToFifty1(int v) { // deep copy
    v = 50;
}

void ChangeToFifty2(int *v) { // shallow copy
    *v = 50;
}

int main() {
    // deep copy
    int x = 100;
    int y = x;
    y = 50;
    std::cout << x << std::endl; // 100

    // shallow copy
    int *a = new int(100);
    int *b = a;
    *b = 50;
    std::cout << *a << std::endl; // 50

    // delete b; // compile error
    delete a;

    int c = 100;
    ChangeToFifty1(c);
    std::cout << c << std::endl; // 100

    int d = 100;
    ChangeToFifty2(&d);
    std::cout << d << std::endl; // 50

    return 0;
}