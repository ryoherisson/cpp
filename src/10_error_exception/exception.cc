// コーディング規約による例外処理の使用禁止
// C++ における例外処理は問題点が多く、 Google C++ Style Guide や LLVM Coding Standards では例外処理の使用を原則禁止しています。


#include <iostream>
#include <string>

int CharToInt(const char c) {
    switch (c) {
        case '0':  return 0;
        case '1':  return 1;
        case '2':  return 2;
        case '3':  return 3;
        case '4':  return 4;
        case '5':  return 5;
        case '6':  return 6;
        case '7':  return 7;
        case '8':  return 8;
        case '9':  return 9;
        default:
            // 関数から例外を送出
            throw std::runtime_error("数値ではない文字が入っています");
    }
}

int StringToInt(const std::string& str) {
    int num = 0;
    for (const auto s : str) {
        num *= 10;

        // CharToInt から例外が送出される
        num += CharToInt(s);
    }
    return num;
}

int main() {
    std::string str = "123XY56";
    try {
        // StringToInt 内部の CharToInt から例外が送出される
        auto num = StringToInt(str);

        std::cout << num << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}