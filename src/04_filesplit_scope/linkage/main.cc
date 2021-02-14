#include <iostream>
#include "other.h"

namespace {
    int hoge = 0;
}

int main() {
    Print();

    hoge += 2;

    IncrementHoge();
    std::cout << "main.cc: " << hoge << std::endl;
    PrintHoge();

    // std::cout << x << std::endl; // compile error

    return 0;
}