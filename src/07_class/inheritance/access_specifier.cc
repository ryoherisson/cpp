class AccessSpecifier {
    void Private1();  // デフォルトは private

 public:
    void Public1();
    void Public2();

 public:  // 対象となるメンバがなくても問題なし
 private:
    void Private2();

 private:  // アクセスレベルの変化がなくても問題なし
    void Private3();
};