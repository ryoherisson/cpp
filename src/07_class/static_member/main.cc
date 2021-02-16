#include <iostream>
#include "counter.h"

int main() {
    ++Counter::count_;
    std::cout << Counter::count_ << std::endl; // 11

    return 0;
}

