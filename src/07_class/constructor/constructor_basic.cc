#include <iostream>

class Rectangle {
    public:
        Rectangle(int height, int width);
        // Rectangle() : height_(0), width_(0) {};

        int Area() const {
            return height_ * width_;
        };

    private:
        const int height_;
        const int width_;
};

// constructor
Rectangle::Rectangle(int height, int width) : height_(height), width_(width) {};

// copy constructor
class Copyable {
    public:
        Copyable(); // デフォルトコンストラクタ
        Copyable(const Copyable& c); // コピーコンストラクタ
};

// move constructor
class Movable {
    public:
        Movable();
        Movable(Movable&& m);
};

// 変換コンストラクタ (値を一つだけ受け取るコンストラクタ)
class Square {
    public:
        explicit Square(int size) : size_(size) {}

        int Area() const {
            return size_ * size_;
        }

    private:
        int size_;
};

int main() {

    Rectangle r(10, 20);

    Copyable c1;  // デフォルトコンストラクタでオブジェクト作成
    Copyable c2(c1);  // コピーコンストラクタでオブジェクト作成

    Movable m1;  // デフォルトコンストラクタでオブジェクト作成
    Movable m2(std::move(m1));  // ムーブコンストラクタでオブジェクト作成

    Square s(10);
    // Square s = 10;



    return 0;
}