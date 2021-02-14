#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

int main() {
    std::vector<int> x = {10, 1, 2, 3, 4};

    auto it = x.begin();

    std::cout << *it << std::endl; // 10

    ++it;

    std::cout << *it << std::endl; // 1

    for (auto it = x.begin(); it != x.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // setでも使える
    std::set<int> y = {0, 1, 2, 3, 4};

    for (auto it = y.begin(); it != y.end(); ++it) {
        std::cout << *it << std::endl;
    }


    // std::count_if は条件を満たすコンテナ要素の個数を数える処理
    //   - 第1引数と第2引数で範囲を指定
    //   - 第3引数で関数オブジェクトで条件を指定(lambda)
    auto n = std::count_if(x.begin(), x.end(), [](const int v) {
    // 0 より大きい 2 の倍数
        if (v <= 0) {
            return false;
        }
        if (v % 2 != 0) {
            return false;
        }
        return true;
    });
    std::cout << n << std::endl;  // 3

    // コンテナライブラリに使える
    // std::array
    // std::vector
    // std::map
    // std::set
    // std::unordered_map
    // std::unordered_set

    std::map<std::string, int> persons = {
        {"Alice", 18},
        {"Bob", 20}
    };

    for (auto it = persons.begin(); it != persons.end(); ++it) {
        const auto& person = *it;  // std::pair<std::string, int>
        const std::string& name = person.first;
        const int age = person.second;
        std::cout << name << ": " << age << std::endl;
    }

    // 前方向イテレータ
    // イテレータを動かす場合に前に進めることだけができます。
    // std::unordered_map や std::unordered_set のイテレータが該当します。

    // std::unordered_set<int> x = {0, 1, 2, 3, 4};

    // auto it = x.begin();
    // std::cout << *it << std::endl;

    // ++it;  // 前に進める
    // std::cout << *it << std::endl;

    // 双方向イテレータ
    // イテレータを動かす場合に前に進めるだけでなく、後ろへ戻すことができます。
    // std::map や std::set のイテレータが該当します。

    // std::set<int> x = {0, 1, 2, 3, 4};

    // auto it = x.begin();
    // std::cout << *it << std::endl;  // 0

    // ++it;  // 前に進める
    // std::cout << *it << std::endl;  // 1

    // --it;  // 後ろへ戻す
    // std::cout << *it << std::endl;  // 0

    // ランダムアクセスイテレータ
    // イテレータを動かす場合に任意の位置へ動かすことができます。
    // std::array や std::vector のイテレータが該当します。

    // std::vector<int> x = {0, 1, 2, 3, 4};

    // auto it = x.begin();
    // std::cout << *it << std::endl;  // 0

    // ++it;  // 前に進める
    // std::cout << *it << std::endl;  // 1

    // --it;  // 後ろへ戻す
    // std::cout << *it << std::endl;  // 0

    // it = it + 3;  // 3つ前に進める
    // std::cout << *it << std::endl;  // 3

    // // it は変更せずに it から2つ後ろへ戻した要素を参照
    // std::cout << it[-2] << std::endl;  // 1 (it から2つ後ろへ戻した要素)
    // std::cout << *it << std::endl;  // 3 (it は変更されていない)


    // iteratorの参照の無効化
    // std::vector<int> x = {0, 1, 2, 3, 4, 5, 6};
    // auto it1 = x.begin() + 2;
    // auto it2 = x.begin() + 3;
    // auto it3 = x.begin() + 4;
    // std::cout << *it1 << std::endl;  // 2
    // std::cout << *it2 << std::endl;  // 3
    // std::cout << *it3 << std::endl;  // 4

    // x.erase(x.begin() + 3);  // index=3 の要素を削除

    // std::cout << *it1 << std::endl;  // 2 (有効なまま)
    // std::cout << *it2 << std::endl;  // 未定義動作 (無効化される)
    // std::cout << *it3 << std::endl;  // 未定義動作 (無効化される)

    return 0;
}