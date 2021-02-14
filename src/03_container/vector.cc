#include <iostream>
#include <vector>

int main() {
    std::vector<int> x = {0, 1, 2, 3, 4};

    x[2] = 10;

    auto size = x.size();

    x.emplace_back(5);
    auto size2 = x.size();
    std::cout << size2 << std::endl; // 6


    x.pop_back();
    auto size3 = x.size();
    std::cout << size3 << std::endl; // 5

    auto px = x.data();
    auto num = *px;
    std::cout << px << std::endl; // 0x7ff687c059b0
    std::cout << num << std::endl; // 0

    return 0;
}