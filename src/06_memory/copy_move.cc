#include <iostream>
#include <vector>

void Print(std::string&) {
    std::cout << "左辺値参照" << std::endl;
}

void Print(std::string&&) {
    std::cout << "右辺値参照" << std::endl;
}


int main() {
    // cost高い
    // std::vector<int> x(10000000);
    // std::vector<int> y = x; // deep copy

    // move でもこれは最新の注意が必要
    // std::vector<int>* x = new std::vector<int>(10000000);
    // std::vector<int>* y = x; // shallow copy
    // x = nullptr

    // 左辺値: 基本的にそのスコープの間生き続ける名前付きのオブジェクト
    // 右辺値: リテラルや関数が返す一時オブジェクトのようなその瞬間に破棄されて不要になるもの

    // move
    std::vector<int> x(100000);
    std::vector<int> y = std::move(x); // std::moveでxを右辺値にキャスト
    // 以降xは使用しない

    // 右辺値の参照
    int&& z = 100;
    std::cout << z << std::endl; // 100

    std::string str = "hoge";

    Print(str);
    Print(std::move(str));

    return 0;
}