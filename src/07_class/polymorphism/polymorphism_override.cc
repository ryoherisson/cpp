#include <iostream>

class Polygon {
    public:
        virtual int Area() const = 0;
};

class Rectangle : public Polygon {
    public:
        virtual void Describe() const {
            std::cout << "height = " << height_ << std::endl;
            std::cout << "width = " << width_ << std::endl;
        }

        int Area() const override {
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

        void Describe() const override {
            std::cout << "size = " << height_ << std::endl;
        }
};


int main() {
    Square s;
    s.SetSize(10);

    const Rectangle& r = s;
    r.Describe();

    return 0;
}