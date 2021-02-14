#include <iostream>
#include <functional>

int Add(int x, int y) {
    return x + y;
}

int main() {
    int c = 5;

    // auto 変数名 = [ キャプチャ ]( 引数リスト ) -> 戻り値の型 { 処理内容 };
    auto func = [&](int a, int b) -> int {c = 10; return c + a + b;}; // auto 変数名 = [ キャプチャ ]( 引数リスト ) -> 戻り値の型 { 処理内容 };

    int result = func(4, 6);
    std::cout << result << std::endl; // 20
    std::cout << c << std::endl; // 10

    /*
    キャプチャ
        [=]	ラムダ式定義時に存在する全ての変数をコピーしてラムダ式の中で使う
        [&]	ラムダ式定義時に存在する全ての変数を参照してラムダ式の中で使う
        [a]	変数 a をコピーしてラムダ式の中で使う
        [&a]	変数 a を参照してラムダ式の中で使う
        [&a, b]	変数 a は参照し、変数 b はコピーしてラムダ式の中で使う
        [=, &a]	変数 a は参照し、それ以外はコピーしてラムダ式の中で使う
    */

    int init = 5;

    auto f = [init](int a, int b) {return init + a * b;}; // copy capture. init=10はできない
    auto g = [&init](int a, int b) {return init + a * b;}; // reference capture

    init = 0;

    // 【コピーキャプチャの場合】
    //    ラムダ式の定義時点で init がコピーされているので、ラムダ式内の init は 5
    int result_copy = f(2, 4);
    std::cout << result_copy << std::endl; // 13;

    // 【参照キャプチャの場合】
    //    ラムダ式実行時の init の値が参照されるので、ラムダ式内の init は 0
    int result_ref = g(2, 4);
    std::cout << result_ref << std::endl; // 8


    // 引数リスト
    auto func1 = [](int x) -> int { return x * x; };  // int を引数とする
    auto func2 = []() -> int { return 400; };         // 引数なし
    auto func3 = [] { return 400; };                  // 戻り値の型の記述を省略した場合、 () ごと省略可能
    auto func4 = [](int a, int b) { return a + b; };  // a, b は共に int なので、戻り値も int と推論される


    // キャプチャを持たないラムダ式であれば関数ポインタに暗黙変換することが出来ます。
    int (*fp)(int, int) = [](int x, int y) { return x + y; };


    // std::function
    std::function<int(int, int)> func_s = Add; // std::function<戻り値の型(引数の型)> 変数名
    int res = func_s(3, 5);                    // fを介して関数Addが実行
    std::cout << res << std::endl;             // 8

    func_s = [](int x, int y) {return x * y;}; // ラムダ式も保持可能
    std::cout << func_s(4, 7) << std::endl;     // 28

    return 0;
}