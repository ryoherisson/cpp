#include <iostream>

int z = 100;

namespace A {
    int count = 2;
    // namespace A

    int GetCount() {
        return count;
    }

    namespace P {
        int count = 10;

        int GetCount() {
            return count;
        }
        namespace X {

            int GetCount() {
                return count; // A::P::countが利用
            }
        }

    } // namespace P
} // namespace A

namespace B {
    int count = 4;
    // namespace B
}

int GetCount() {
    int x = 5;
    return x;
}

int main() {
    std::cout << A::count << std::endl; // 2
    std::cout << B::count << std::endl; // 4

    std::cout << A::P::GetCount() << std::endl; // 10
    std::cout << A::P::X::GetCount() << std::endl; // 10

    int x = GetCount();
    std::cout << x << std::endl; // 5

    int y = 3;
    {
        int y = 5;
        std::cout << y << std::endl; // 5
    }
    {
        int y = 9;
        std::cout << y << std::endl; // 9
    }

    std::cout << y << std::endl; // 3

    std::cout << z << std::endl; // 100

    int z = 10;
    std::cout << z << std::endl; // 10
    std::cout << ::z << std::endl; // 100 global scope

    return 0;
}