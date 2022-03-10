#include <gtest/gtest.h>
#include "calc.h"

TEST(calc, test1)
{
    ASSERT_EQ(Add(1, 5), 6);
    ASSERT_EQ(Add(1, 6), 7);
}