#include "other.h"
#include <iostream>

// static int x = 246; // 内部リンケージ. other.cc内でのみ参照可能


// C++ において static は 様々な意味を持つ ため、分かりづらいキーワードとなっています。
// 宣言に内部リンケージを持たせる場合は、 static ではなく無名名前空間を使うようにしましょう。
namespace {
    int x = 50;
} // unnamed namespaced

namespace {
    int hoge = 0; // other.cc 内のhoge
}

void IncrementHoge() {
    ++hoge;
}

void Print() {
    std::cout << x << std::endl;
}

void PrintHoge() {
     std::cout << "other.cc: " << hoge << std::endl;  // other.cc: 1
}