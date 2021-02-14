#include <iostream>
#include <tuple>

int main() {
    std::tuple<std::string, int> person {"Bob", 20};
    std::tuple<std::string, int, std::string> person2 {"Bob", 20, "USA"};

    // 初期化の方法
    // std::tuple<std::string, int> person { "Bob", 20 };
    // std::tuple<std::string, int> person("Bob", 20);
    // std::tuple<std::string, int> person = std::make_tuple("Bob", 20);

    std::string s = std::get<0>(person);
    int x = std::get<1>(person);

    std::cout << x << std::endl;

    std::string name;
    int age;
    std::string country;

    std::tie(name, age, country) = person2;  // name: "Bob", age: 20, country: "USA"
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << country << std::endl;

    return 0;
}
