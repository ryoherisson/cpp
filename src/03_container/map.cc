#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    // keyでソートして管理. キーの順番を保持
    std::map<std::string, int> persons = {
        {"Alice", 18},
        {"Bob", 20}
    };

    // unordered map
    // hashで管理
    // std::unordered_map<std::string, int> persons = {
    //     {"Alice", 18},
    //     {"Bob", 20}
    // };

    std::cout << persons["Alice"] << std::endl; // 18
    std::cout << persons["Bob"] << std::endl; // 20

    persons.insert({"Eve", 19});

    persons.erase("Bob");

    return 0;
}