#include <bitset>
#include <iostream>

int main() {
    auto bits_a  = std::bitset<8>("00001111"); // 15を8bitで表す
    std::cout << ~bits_a << std::endl; // 否定：11110000
    std::cout << (bits_a << 2) << std::endl; // 左に2シフト：00111100
    std::cout << (bits_a >> 2) << std::endl; // 右に2シフト：00000011

    auto bits_b = std::bitset<8>("00111100"); // 60を8bitで表す
    std::cout << (bits_a & bits_b) << std::endl; // 論理積: 00001100
    std::cout << (bits_a | bits_b) << std::endl; // 論理和: 00111111
    std::cout << (bits_a ^ bits_b) << std::endl; // 排他的論理和: 00110011

    // 数値型でもビット演算は行なえます。 ビットを取り扱う際は、 unsigned が付いた符号なし整数型を利用することが望ましいです。
    unsigned int a = 0x0000000f;            // 15
    std::cout << std::showbase << std::hex; // 基数のプレフィックスを出力 + 16進法で出力 std::coutの設定
    std::cout << ~a << std::endl;           // 0xfffffff0
    std::cout << (a << 2) << std::endl;     // 0x3c
    std::cout << (a >> 2) << std::endl;     // 0x3

    unsigned int b = 0x0000003c;        // 60
    std::cout << (a & b) << std::endl;  // 0xc
    std::cout << (a | b) << std::endl;  // 0x3f
    std::cout << (a ^ b) << std::endl;  // 0x33

    return 0;
}