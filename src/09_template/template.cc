#include <iostream>

// 型やコンパイル時に定まる値をパラメータ化する機能をテンプレートといいます。
// 型に依存せず処理を共通化するために使用されます。
template <typename T>
T Sum(T a, T b) {
    return a + b;
}

template <typename T, typename U>
double Sum2(T a, U b) {
    return a + b;
}

// 戻り値の型推論
template <typename T, typename U>
auto Sum3(T a, U b) -> decltype(a + b) {
    return a + b;
}


// compile時に決まる値のパラメータ
template <int N>
int Fibonacchi() {
    int a[N + 1];
    a[0] = 0;
    a[1] = 1;
    for (auto i = 2; i <= N; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[N];
}


int main() {
    Sum<int>(1, 2); // 3
    Sum<double>(1.2, 3.4); // 4.6

    // これでも呼び出せる
    // Sum(1, 2);
    // Sum(1.2, 3.4);
    // Sum(1, 3.4); // 推論できないのでコンパイルエラー

    std::cout << Sum2(1, 2.3) << std::endl; // 3.3

    std::cout << Fibonacchi<10>() << std::endl; // 55

    return 0;
}