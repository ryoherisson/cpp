#ifndef SUM_H_
#define SUM_H_

// 関数テンプレートの定義
template <typename T>
T Sum(T a, T b) {
    return a + b;
}

//暗黙的実体化を阻止
extern template int Sum<int>(int, int);
#endif  // SUM_H_