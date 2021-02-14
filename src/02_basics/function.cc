#include <iostream>

void HelloWorld(int n);
void Print(int x);
void Print(double x);
int Add(int x, int y);


int main(int argc, char *argv[]) {

    int i = atoi(argv[1]);

    std::cout << i << std::endl;

    HelloWorld(i);

    // int
    Print(i);
    // // double
    double x = 2.001;
    Print(x);

    // 関数ポインタ
    int (*fp)(int, int) = Add; // 関数Addのアドレスを保持するポインタ fp
    int result = fp(3, 5);  // 関数ポインタfpを介して関数Addが実行される
    std::cout << result << std::endl; // 8

    return 0;
}

void HelloWorld(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "[" << i << "]" << "Hello World!" << std::endl;
    }
}

void Print(int x) {
    std::cout << "int: " << x << std::endl;
}

void Print(double x) {
    std::cout << "double: " << x << std::endl;
}

int Add(int x, int y) {
    return x + y;
}