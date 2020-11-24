#ifndef TST_DISTANCE_H
#define TST_DISTANCE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../include/Point.h"

using namespace testing;

TEST(test_point, distance_normal)
{
    Point p1("A",1.0,3.0);
    Point p2("B",4.0,7.0);
    double d = p1.distance(p2);
    ASSERT_EQ(5, d);
}

TEST(test_point, distance_big)
{
    Point p1("A",1.0E307,3.0E307);
    Point p2("B",4.0E307,7.0E307);
    double d = p1.distance(p2);
    ASSERT_EQ(5E307, d);
}
#endif // TST_DISTANCE_H
