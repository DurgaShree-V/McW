#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(Testcase1, Subtestcase) {
    EXPECT_EQ(11, 11);
    EXPECT_TRUE(1 != 2);
    cout<<"Condition failed after expect" << endl;
   
    ASSERT_EQ(1,1);
    cout<<"Condition failed after assert" << endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}