#include <iostream>

class Rectangle {
    public:
        // int Area() {
        //     return height_ * width_;
        // }
        int Area() const;

        int height_;
        int width_;
};

// constをつけるとデータメンバ（メンバ変数）の変更ができなくなる
int Rectangle::Area() const {
    int x = this->height_;
    int y = this->width_;
    return height_ * width_;
}

int main() {

    Rectangle rect;
    rect.height_ = 10;
    rect.width_ = 20;

    Rectangle rectangle;
    Rectangle *r = &rectangle;
    (*r).height_ = 10;
    (*r).width_ = 20;

    std::cout << (*r).height_ * (*r).width_ << std::endl;

    r->height_ = 10;
    r->width_ = 50;

    std::cout << r->height_ * r->width_ << std::endl;

    std::cout << (*r).Area() << std::endl;
    std::cout << r->Area() << std::endl;

    return 0;
}