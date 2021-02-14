#include <iostream>
#include <cstdint>

// 列挙型
enum Day {
    Sun, // 0
    Mon, // 1
    Tue, // 2
    Wed, // 3
    Thu, // 4
    Fri, // 5
    Sat  // 6
};

enum class Day2 {
    Sun, // 0
    Mon, // 1
    Tue, // 2
    Wed, // 3
    Thu, // 4
    Fri, // 5
    Sat  // 6
};

enum class SolarSystem {
  Sun,  // Day::Sun と SolarSystem::Sun は区別されるためOK
  Mercury,
  Venus,
  Earth,
  Mars,
  Jupiter,
  Saturn,
  Uranus,
  Neptune
};

int main() {
    bool ok = true;

    char x = 'x';

    unsigned int y = 4000000000;

    // サイズ型付き整数型
    std::int32_t z = 5;

    float a = 1.00000;
    double b = 2.000000000;

    // enum
    int t = Fri;
    std::cout << t << std::endl; // 5

    // Day day = 5; // compile error
    Day day = Fri;
    std::cout << day << std::endl; // 5

    // enum class
    Day2 day2 = Day2::Fri;
    // Day2 day2 = Fri; // compile Error
    int d = static_cast<int>(day2); // enum classの型変換
    std::cout << d << std::endl; // 5

    return 0;
}