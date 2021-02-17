#include <cassert> // assert必要
#include <iostream>
#include <limits>
#include <vector>

int Max(const std::vector<int> & v) {
    assert(!v.empty());

    int max = std::numeric_limits<int>::min();
    for (auto e : v) {
        if (e > max) {
            max = e;
        }
    }
    return max;
}


// static_assert コンパイル時にエラー
template <typename T, int N>
class Array {
    static_assert(N > 0, "サイズは0より大きくなければなりません");

    public:
        int size() const {return N;}

        T data_[N];
};


int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2;

    std::cout << Max(v1) << std::endl;
    // std::cout << Max(v2) << std::endl;

    Array<int, 0> a;

    return 0;
}