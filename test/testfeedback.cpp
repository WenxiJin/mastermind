#include "gtest/gtest.h"
#include "feedback.c"

TEST(feedback_test, non_duplicate) {
    EXPECT_EQ(40, feedback(1234, 1234));
    EXPECT_EQ( 2, feedback(8912, 3689));
    EXPECT_EQ(10, feedback(1234, 5674));
    EXPECT_EQ(30, feedback(1235, 1234));
    EXPECT_EQ( 4, feedback(1234, 3412));
    EXPECT_EQ(22, feedback(1234, 1324));
}


