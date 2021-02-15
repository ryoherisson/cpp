class Rectangle {
 public:
    int Area() const {
        height_ * width_;  // 参照可
    }

 public:
    int height_;
    int width_;
};

class Square : public Rectangle {
 public:
    void SetSize(int size) {
        height_ = size;  // 参照可
        width_ = size;   // 参照可
    }
};

int main() {
    Rectangle r;
    r.height_ = 10;  // 参照可
    r.width_ = 20;   // 参照可

    Square s;
    s.SetSize(10);
    return 0;
}