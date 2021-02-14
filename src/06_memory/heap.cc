#include <iostream>

void Function() {
    int *p = new int[10000];

    delete[] p;
    // deleteせずにFunction()が終了すると、
    // int[10000]のメモリが解放されないままになる
}

int main() {

    int *p1 = new int(100);
    int *p2 = new int[5]; // 配列

    std::cout << p1 << std::endl; //0x7fb3b1405990
    std::cout << *p1 << std::endl; //100

    delete p1;
    delete[] p2; // 配列

    Function();

    return 0;
}