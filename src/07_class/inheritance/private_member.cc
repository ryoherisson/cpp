#include <iostream>

class Rectangle {
    public:
        int Area() const {
            return height_ * width_;
        }

    private:
        int height_;
        int width_;
};

class Square: public Rectangle {
    public:
        void SetSize(int size) {
            // height_ = size; // compile error
            // width_ = size; // compile error
        }
};

int main() {
    Rectangle r;
    // r.height_ = 10; // compile error
    // r.width_ = 20; // compile error

    Square s;
    s.SetSize(10);
    std::cout << s.Area() << std::endl;

    return 0;
}