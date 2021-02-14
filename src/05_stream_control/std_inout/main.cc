#include <iostream>

int main() {
    std::cerr << "標準エラー出力" << std::endl;

    std::cout << "好きな食べ物を入力してください: ";
    std::string food;
    std::cin >> food;
    std::cout << "好きな食べ物は " << food << " です。" << std::endl;

    int x = 0;

    std::cout << "整数を入力してください: ";
    if (std::cin >> x) {
        std::cout << "入力した整数は " << x << " です。" << std::endl;
    } else {
        std::cout << "不正な入力です。" << std::endl;
    }

    return 0;
}