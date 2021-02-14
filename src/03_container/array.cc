#include <iostream>
#include <cstddef>
#include <array>

// 配列の要素数を求める方法としてC++11より前ではプリプロセッサマクロを使用するのが一般的でしたが、
// C++11からは次のようにして求めることができます。この関数はC++17以降では std:size という関数として標準ライブラリに存在します。
template <class T, std::size_t N>
constexpr std::size_t size(const T (&)[N]) noexcept { return N; }

void PrintArray(const int* x, std::size_t num) {
    for (std::size_t i = 0; i < num; i++) {
        std::cout << x[i] << std::endl;
    }
}

int main() {
    int x[5] = {0, 1, 2, 3, 4,};
    int y[] = {0, 1, 2, 3, 4, 5};

    int z[5];
    z[0] = 1;
    z[1] = 2;
    z[2] = 3;
    z[3] = 4;
    z[4] = 5;

    for (int i = 0; i < 5; i++) {
        std::cout << x[i] << std::endl;
    }

    // 配列はいくつかの例外を除いて常にポインタ型に暗黙変換されます。
    int t[] = {2, 4, 6, 8, 10};
    int *p = t;
    std::cout << t << std::endl; // 0x7ffee37886c0
    std::cout << p << std::endl; // 0x7ffee37886c0
    std::cout << *p << std::endl; // 2
    std::cout << *(p + 1) << std::endl; // 4
    std::cout << *(p + 2) << std::endl; // 6
    std::cout << *(p + 3) << std::endl; // 8
    std::cout << *(p + 4) << std::endl; // 10

    constexpr std::size_t num = 5;
    int a[num] = {0, 1, 2, 3, 4};

    PrintArray(a, num);

    int arr[3];
    static_assert(size(arr) == 3, "");

    std::array<int, 5> c = {{0, 1, 2, 3, 4}}; // C++11では{{}}
    //std::array<int, 5> c = {0, 1, 2, 3, 4}; // C++14～

    c[2] = 10;

    auto size = c.size();
    //auto size = std::size(x);  // C++17～

    int arr1_1[3] = {};
    //int arr1_2[3] = arr1_1;//NG
    std::array<int, 3> arr2_1{};
    arr2_1[0] = 10;
    std::array<int, 3> arr2_2 = arr2_1;//OK
    std::cout << arr2_2[0] << std::endl; // 10

    return 0;
}