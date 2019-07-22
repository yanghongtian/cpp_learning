#include <common.h>


TEST(function, expect) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(1 == 1);
    EXPECT_FALSE(0 == 1);
    EXPECT_NE(1, 2);
    EXPECT_LT(1, 2);
    EXPECT_LE(2, 2);
    EXPECT_GT(3.0, 2.f);
    EXPECT_GE(3, 3.0000000001);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
