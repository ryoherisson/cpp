#include "hello_world.h"
#include "something.h"

// inline 関数は定義が同一である場合に限って、 異なるソースファイルで同一の定義をしてもいいと決められています.
// inline void HelloWorld() {
//     std::cout << "Hello World!" << std::endl;
// }

int main() {
    HelloWorld();
    Something();
    return 0;
}