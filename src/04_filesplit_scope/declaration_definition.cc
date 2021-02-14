#include <iostream>

// 宣言
void HelloWorld();
void HelloWorld(); // 重複してもOK

int main() {
    // 定義(宣言も兼ねる)
    int x;

    // 初期化
    x = 10;

    HelloWorld();

    return 0;
}

// 定義
void HelloWorld() {
    std::cout << "Hello World" << std::endl;
}