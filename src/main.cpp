#include <stdlib.h>
#include "raylib/example.hpp"
#include "gtest/gtest.h"

int add(int a, int b) {
    return a + b;
}

TEST(MyMathTest, AddTest) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(-1, -2), -3);
    EXPECT_EQ(add(0, 0), 0);
}

int main(int argc, char **argv) {
    system("CLS");

    ::testing::InitGoogleTest(&argc, argv);

    //raylib_example();

    return RUN_ALL_TESTS();
}