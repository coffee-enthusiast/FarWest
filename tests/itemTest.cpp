#include "gtest/gtest.h"
#include "../CE/include/Player.h"
#include "../CE/include/Item.h"


//  Global tracing boolean
bool isTracingActive;
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
