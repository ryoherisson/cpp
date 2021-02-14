#include <iostream>
#include <vector>

int main() {
    std::vector<int> x = {0, 1, 2, 3, 4};

    for (auto it = x.begin(); it != x.end(); ++it) {
        std::cout << *it << std::endl;
    }

    for (auto&& e : x) {
        std::cout << e << std::endl;
    }

    int y[] = {0, 1, 2, 3, 4};

    for (auto&& e : y) {
        std::cout << e << std::endl;
    }

    return 0;
}