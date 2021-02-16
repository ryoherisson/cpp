#include <iostream>

enum class Day {
    Sun, // 0
    Mon, // 1
    Tue, // 2
    Wed, // 3
    Thu, // 4
    Fri, // 5
    Sat, // 6
};

class Square {
    public:
        explicit Square(int size) : size_(size) {}

    private:
        int size_;
};


int main() {

    double dx = 3.14;
    int x = static_cast<int>(dx);

    Day day1 = static_cast<Day>(1); // Day::Mon
    int day2 = static_cast<int>(Day::Tue); // 2

    // 型変換を明示的に行うことで、 explicit 指定された変換コンストラクタによる変換も行うことができる.
    Square square = static_cast<Square>(10);

    return 0;
}