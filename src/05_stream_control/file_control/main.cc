#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("file.txt"); // 読み込むファイルのパス指定
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    std::ofstream file2("fruits.txt"); // 書き出すファイルのパス指定
    std::vector<std::string> fruits = {"apple", "strawberry", "pear", "grape"};

    for (const auto fruit : fruits) {
        file2 << fruit << std::endl; // 書き出し
    }

    // 書き出す前に、既に同名のファイルが存在していた場合、中身は上書きされます。
    // 上書きせずに追記する場合は、コンストラクタの引数に std::ios::app を追加します。
    std::ofstream file3("file.txt", std::ios::app);
    std::string quatation("--- William Shakespeare's Epitaph");

    file3 << std::endl << quatation;

    return 0;
}