#include <iostream>

int main() {
    int x = 5;
    int* p = &x;


    // null pointer. どの変数も参照していないポインタ
    int *q = nullptr;

    // derefernce 逆参照
    // 変数からポインタを得るときには & を付け, ポインタから値を得るには * を付けます.
    int y = *p;

    int z = 123;
    const int* r = &z;
    // *r = 456; // error

    int a = 100;
    int *s = &a; // pointer
    int &t = a; // reference

    // ポインタが指し示す値を扱うには * を付けてデリファレンスする必要がありますが、 参照では何も付与する必要がないため、見た目上では値型のように使うことが出来ます。

    *s = 200;
    t = 200;

    std::cout << t << std::endl;

    return 0;
}