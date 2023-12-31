#include "gtest/gtest.h"
#include "../CE/include/Player.h"
#include "../CE/include/Item.h"

// Test case for Add function
TEST(ItemTest, ConsumeItem) {

    Player p;
    p.playerAttributes[1] = 0;
    p.playerAttributes[2] = 0;
    std::vector<std::pair<int,int>> gains;
            gains.push_back(std::make_pair(SP, 2));
            gains.push_back(std::make_pair(HP, 5));
    Item drink = Item("Cola", CONSUMABLE, gains);

    p.Consume(drink);

    // Assert
    ASSERT_EQ(p.playerAttributes[1], 5);
    ASSERT_EQ(p.playerAttributes[2], 2);
}
TEST(InventoryTest, SimpleItem) {

    Player p;

    ASSERT_EQ(p.playerInventory.items.size(), 0);
    ASSERT_EQ(p.playerInventory.maxItems, 5);

    std::cout << p.playerInventory.PrintInventory();

        std::vector<std::pair<int,int>> gains;
            gains.push_back(std::make_pair(SP, 2));
            gains.push_back(std::make_pair(HP, 5));
    Item drink = Item("Cola", CONSUMABLE, gains);

    p.playerInventory.AddItem(&drink);
    std::cout << p.playerInventory.PrintInventory();

    // Assert
    ASSERT_EQ(p.playerInventory.items.size(), 1);
}

//  Global tracing boolean
bool isTracingActive;
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
