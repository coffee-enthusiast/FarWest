#include "gtest/gtest.h"
#include "../CE/include/Skill.h"

// Test case for Add function
TEST(SkillTest, TrainSkill) {

    Skill s = Skill("", 1, 0, 10, 2);
    s.trainSkill(10);
    // Assert
    ASSERT_EQ(s.maxSkillLevel, 2);
    ASSERT_EQ(s.skillBufferMax, 10);
    ASSERT_EQ(s.skillLevel, 2);
    ASSERT_EQ(s.skillBufferAmount, 0);
}
//  Global tracing boolean
bool isTracingActive;
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
