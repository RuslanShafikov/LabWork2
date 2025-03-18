/*# LabWork2
Shafikov Ruslan Alvirtovich, group 24.Б83 - мм
st112650@stdudent.spbu.ru
*/

#include <gtest/gtest.h>
#include <iostream>

TEST(SimpleTest, EqualityTest) {
    EXPECT_EQ(2222222222222222, 2222222222222222);
}

int main_test(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
