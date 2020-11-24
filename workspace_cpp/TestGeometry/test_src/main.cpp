/**
  *
  *  Googletest sur Github
  *  	https://github.com/google/googletest
  *  Alternatives: boost, QtTest
  *  Doc: assertions
  *     https://github.com/google/googletest/blob/master/googletest/docs/primer.md
  *
  */

#include "../test_include/tst_distance.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
