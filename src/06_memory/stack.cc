#include <iostream>

void Function() {
    int x = 100; // スタック
    int y = 200; // スタック
} // 関数の終了とともにx, yはスタックから取り除かれる

int main() {
    Function();
    return 0;
}