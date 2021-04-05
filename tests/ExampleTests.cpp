#include <gtest/gtest.h>

#include "../Example.hpp"

struct ExampleTestsFixture : public ::testing::Test {
    int *x;

    int GetX() {
        return *x;
    }

    virtual void SetUp() override {
        x = new int(42);
    }

    virtual void TearDown() override {
        delete x;
    }
};

TEST(ExampleTests, DemonstratedGTestMacros) {
    EXPECT_TRUE(true);
}

TEST(ExampleTests, MAC) {
    int x = 42;
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + x * y;
    EXPECT_EQ(
            expectedNewSum,
            MAC(x, y, sum));
    EXPECT_EQ(
            expectedNewSum,
            sum);
}

TEST(ExampleTests, Square) {
    int x = 5;
    int expectedSquare = x * x;
    EXPECT_EQ(
            expectedSquare,
            Square(x));
}

TEST_F(ExampleTestsFixture, Square) {
    int expectedSquare = GetX() * GetX();
    EXPECT_EQ(
            expectedSquare,
            Square(GetX()));
}

TEST_F(ExampleTestsFixture, MAC) {
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedSum = oldSum + GetX() * y;
    EXPECT_EQ(
            expectedSum,
            MAC(GetX(), y, sum));
    EXPECT_EQ(
            expectedSum,
            sum);
}
