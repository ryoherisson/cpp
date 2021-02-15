#include <iostream>

class Rectangle {
    public:
        int Area() const {
            return height_ * width_;
        }

        int height_;
        int width_;
};

class Square : public Rectangle {
    public:
        void SetSize(int size) {
            height_ = size;
            width_ = size;
        }
};


int main() {
    Square s;
    s.SetSize(10);

    const Rectangle& r = s;
    std::cout << "area = " << r.Area() << std::endl;

    return 0;
}