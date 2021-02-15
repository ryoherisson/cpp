class Rectangle {
 public:
    int Area() const {
        height_ * width_;  // 参照可
    }

 protected:
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
    r.height_ = 10;  // コンパイルエラーになります
    r.width_ = 20;   // コンパイルエラーになります

    Square s;
    s.SetSize(10);
    return 0;
}