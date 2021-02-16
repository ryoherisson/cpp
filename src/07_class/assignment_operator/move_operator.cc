#include <iostream>

class Movable {
 public:
    Movable();  // デフォルトコンストラクタ
    Movable(Movable&& m);  // ムーブコンストラクタ
    Movable& operator=(Movable&& m);  // ムーブ代入演算子
};


int main() {

    Movable m1;
    Movable m2 = std::move(m1);  // ムーブコンストラクタを使用
    Movable m3;
    m3 = std::move(m2);  // ムーブ代入演算子を使用

    return 0;
}
