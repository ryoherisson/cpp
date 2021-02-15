#include <iostream>

class Rectangle {
    public:
        Rectangle(int height, int width) : height_(height), width_(width) {
            std::cout << "Rectangle::Rectangle() is called." << std::endl;
        }

        int Area() const {
            return height_ * width_;
        }

    private:
        const int height_;
        const int width_;
};

class Square : public Rectangle {
    public:
        Square(int size) : Rectangle(size, size){
            std::cout << "Square::Square() is called." << std::endl;
        }
};

int main() {
    // 基底クラス => 派生クラスの順
    Square s(10); // Square classのデフォルトコンストラクタ
    std::cout << "area = " << s.Area() << std::endl;

    return 0;
}