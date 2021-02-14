#include <iostream>

int main() {

    std::string s = "Hello!";

    // s.size()でもOK
    for (int i = 0; i < s.length(); i++) {
        std::cout << s[i] << std::endl;
    }
    return 0;
}