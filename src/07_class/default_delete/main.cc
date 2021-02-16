#include <iostream>

/*
以下のメンバ関数は暗黙的に定義されることがある特別なメンバ関数です。

- デフォルトコンストラクタ
- コピーコンストラクタ
- コピー代入演算子
- ムーブコンストラクタ
- ムーブ代入演算子
- デストラクタ
*/

class Square {
    public:
        explicit Square(int size) : size_(size) {}

        Square() = default;

        int Area() const {
            return size_ * size_;
        }

    private:
        int size_;
};

class NonCopyable {
    public:
        NonCopyable() = default;
        // 暗黙的に定義されるコピーコンストラクタとコピー代入演算子を
        // 削除することでコピー禁止クラスを実現できる
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
};


int main() {
    Square s1;
    Square s2(10);

    return 0;
}