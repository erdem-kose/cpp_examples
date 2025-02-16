#include <stdlib.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    system("CLS");

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}