#include <iostream>

class Rectangle {
    public:
        int Area() const {
            return height_ * width_;
        }

        int height_;
        int width_;
};

class Square: public Rectangle {
    public:
        void SetSize(int size) {
            height_ = size;
            width_ = size;
        }
};

int main() {
    Rectangle r;
    r.height_ = 10;
    r.width_ = 20;

    Square s;
    s.SetSize(10);
    std::cout << s.Area() << std::endl;

    return 0;
}