#include <iostream>

class Copyable {
    public:
        Copyable();  // デフォルトコンストラクタ
        Copyable(const Copyable& c);  // コピーコンストラクタ
        Copyable& operator=(const Copyable& c);  // コピー代入演算子
};


int main() {
    Copyable c1;
    Copyable c2 = c1;  // コピーコンストラクタを使用
    Copyable c3;
    c3 = c2;  // コピー代入演算子を使用

    return 0;
}