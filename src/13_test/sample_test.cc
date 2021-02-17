#include <gtest/gtest.h>
#include "sample.h"


// TEST(/* テストケース名(大項目)*/, /* テスト名(小項目) */) {
  // テスト関数内は、通常通り C++ のコードを記述可能
  // テストケース名とテスト名には _ を含んではいけません。
// }

// true/falseのアサーション
// EXPECT_TRUE(condition);  // condition が true か
// EXPECT_FALSE(condition);  // condition が false か

// 2つの値を比較するアサーション
// EXPECT_EQ(expected, actual);  // expected == actual か
// EXPECT_NE(expected, actual);  // expected != actual か
// EXPECT_LT(expected, actual);  // expected < actual か
// EXPECT_LE(expected, actual);  // expected <= actual か
// EXPECT_GT(expected, actual);  // expected > actual か
// EXPECT_GE(expected, actual);  // expected >= actual か


TEST(IsEvenTest, Negative) {
    EXPECT_FALSE(IsEven(-1));
    EXPECT_TRUE(IsEven(-2));
}

TEST(IsEvenTest, Zero) {
    EXPECT_TRUE(IsEven(0));
}

TEST(IsEvenTest, Positive) {
    EXPECT_FALSE(IsEven(1));
    EXPECT_TRUE(IsEven(2));
}

TEST(IsEvenTest, AssertPositive) {
    ASSERT_FALSE(IsEven(1));  // ASSERTテストは失敗すると中断
    std::cout << "中断により、この文字列は出力されない" << std::endl;
    ASSERT_TRUE(IsEven(2));
}

TEST(IsEvenTest, ExpectPositive) {
    EXPECT_FALSE(IsEven(1));  // EXPECTテストは失敗しても続行
    std::cout << "続行のため、この文字列は出力される" << std::endl;
    EXPECT_TRUE(IsEven(2));
}