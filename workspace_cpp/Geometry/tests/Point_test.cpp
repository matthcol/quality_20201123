/*
 * Point_test.cpp
 *
 *  Created on: 24 nov. 2020
 *      Author: Matthias
 */

#include "Point.h"
#include <gtest/gtest.h>


TEST(Distance, DistOK) {
    ASSERT_EQ(2, 1+1);
    ASSERT_EQ(5, 3+2);
    ASSERT_EQ(10, 7+3);
}

TEST(CalcTest, DistBig) {
    ASSERT_EQ(3, 5-2);
    ASSERT_EQ(-10, 5 - 15);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

