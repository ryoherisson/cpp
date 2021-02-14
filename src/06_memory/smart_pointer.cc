#include <iostream>
#include <memory>

int main() {
    // int* a = new int(100);
    // int* b = a;

    // a, bどちらをdeleteするか?

    // std::shared_ptr
    std::shared_ptr<int> x = std::make_shared<int>(100); // int* x = new int(100);の代わり.
                                                         // 所有者は1人。
    {
        std::shared_ptr<int> y = x; // 通常のポインタ同様、コピーすることで所有権が共有される
                                    // 所有者が2人に増える。
        std::cout << *y << std::endl;
    } // yが破棄されて所有者が1人.

    std::cout << *x << std::endl;

    // unique_ptr
    std::unique_ptr<int> a(new int(200));
    // std::unique_ptr<int> b = a; // compile error
    std::cout << *a << std::endl;

    std::unique_ptr<int> b(std::move(a)); // moveは可能
    std::cout << *b << std::endl;

    // auto_ptrは非推奨. C++17では削除. 使わない様にする.

    // weak_ptr
    std::shared_ptr<int> sp = std::make_shared<int>(246);
    std::weak_ptr<int> wp = sp; // sp を監視対象として wp に登録する

    std::shared_ptr<int> sp2 = wp.lock(); // 有効な場合は sp とリソースを共有する sp2 が作られる
    if (sp2) {
        std::cout << *sp2 << std::endl;
    } else {
        std::cout << "リソースは解放済み" << std::endl;
    }

    return 0;
} // 所有者が0人. xのデストラクタで自動的にdelete.