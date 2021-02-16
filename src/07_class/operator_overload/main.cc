#include <iostream>

class Integer {
    public:
        explicit Integer(int value) : value_(value) {}

        int Value() const {
            return value_;
        }

        // メンバ関数
        // Integer operator-() const {
        //     Integer tmp(-Value()); // 演算対象は自オブジェクトを使用
        //     return tmp;
        // }

        // 加算演算子の左辺のメンバ関数に対して、右辺が引数として渡される
        // Integer operator+(const Integer& rhs) const {
        //     Integer tmp(Value() + rhs.Value());  // 左辺は自オブジェクトを使用する
        //     return tmp;
        // }

        // 前置
        Integer& operator++() {
            ++value_;
            return *this;
        }
        // 後置
        Integer operator++(int) {
            Integer tmp(Value());
            ++value_;
            return tmp;
        }

    private:
        int value_;
};

class RealNumber {
    public:
        explicit RealNumber(double value) : value_(value) {}

        double Value() const {
            return value_;
        }

    private:
        double value_;
};

Integer operator-(const Integer& v) {
    Integer tmp(-v.Value());
    return tmp;
}

RealNumber operator-(const RealNumber& v) {
    RealNumber tmp(-v.Value());
    return tmp;
}

Integer operator+(const Integer& lhs, const Integer& rhs) {
    Integer tmp(lhs.Value() + rhs.Value());
    return tmp;
}

RealNumber operator+(const RealNumber& lhs, const RealNumber& rhs) {
    RealNumber tmp(lhs.Value() + rhs.Value());
    return tmp;
}

struct A {
    explicit A(int) { } // こちらが正しい. 暗黙的な型変換で使用されないようにする.
};
struct B {
    // explicit B(A) { } 期待した結果にならない.
    B(A) { }
};

int main() {

    Integer a(2);
    Integer b = -a;
    Integer c = a + b;

    std::cout << a.Value() << std::endl; // 2
    std::cout << b.Value() << std::endl; // -2
    std::cout << c.Value() << std::endl; // 0

    Integer d = ++a;

    std::cout << a.Value() << std::endl; // 3
    std::cout << d.Value() << std::endl; // 3

    Integer e = a++;

    std::cout << a.Value() << std::endl; // 4
    std::cout << e.Value() << std::endl; // 3

    // explicit
    // B d(1); // 0. 型変換されてしまっている. => Aにexplicitをつけることで防ぐ.


    return 0;
}