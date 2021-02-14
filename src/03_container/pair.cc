#include <iostream>
#include <utility>
#include <tuple>

int main() {
    std::pair<std::string, int> person {"Bob", 20};

    std::get<0>(person); // Bob
    std::get<1>(person); // 20

    std::string a = person.first;
    int b = person.second;


    // std::pair<std::string, int> person { "Bob", 20 };
    // std::pair<std::string, int> person("Bob", 20);
    // std::pair<std::string, int> person = std::make_pair("Bob", 20);

    std::string name;
    int age;
    std::tie(name, age) = person;  // name: "Bob", age: 20

    return 0;
}