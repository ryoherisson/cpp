#include <iostream>

template <typename T, typename U>
class Rectangle {
    public:
        Rectangle(T height, U width) : height_(height), width_(width) {}

        // double Area() const {
        //     return height_ * width_;
        // }

        auto Area() const -> decltype(std::declval<T>() * std::declval<U>()) {
            return height_ * width_;
        }

    private:
        const T height_;
        const U width_;
};

template <typename T, int N>
class Array {
    public:
        int size() const {
            return N;
        }

        T data_[N];
};

int main() {

    Rectangle<int, int> r1(10, 20);
    Rectangle<double, double> r2(1.2, 3.4);

    r1.Area(); // 200
    r2.Area(); // 4.08

    return 0;
}