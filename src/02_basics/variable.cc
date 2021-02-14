#include <iostream>

int main() {
    int x = 5;

    int y;
    y = 5;

    const int z = 5;
    // z = 10;

    // 定数. constは実行時に決定, constexprはコンパイル時に決定.
    constexpr int a = 5;

    // 変数型自動推論
    auto b = 5;
    return 0;
}