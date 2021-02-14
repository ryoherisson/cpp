#include <iostream>
#include <set>
#include <unordered_set>

int main() {
    // key
    std::set<std::string> persons = {
        "Alice",
        "Bob"
    };

    // hash
    // std::unordered_set<std::string> persons = {
    //     "Alice",
    //     "Bob"
    // };

    persons.insert("Eve");

    persons.insert("Bob");




    return 0;
}