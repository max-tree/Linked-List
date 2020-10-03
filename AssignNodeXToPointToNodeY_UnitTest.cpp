#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(AssignNodeXToPointToNodeY, WhenNodeXPointsToNodeY_ExpectCorrectResult)
{
    LinkedListNode* nodeX{nullptr};
    LinkedListNode* nodeY{nullptr};

    create_linked_list_head_or_node(nodeX,0);
    create_linked_list_head_or_node(nodeY,0);

    assign_nodeX_to_point_to_node_y(nodeX, nodeY);

    EXPECT_EQ(nodeX->nextNode, nodeY);
    delete nodeX;
    delete nodeY;
}

TEST(AssignNodeXToPointToNodeY, WhenNodeXHasNotBeenGivenMemory_ExpectNoChange)
{
    LinkedListNode* nodeX{nullptr};
    LinkedListNode* nodeY{nullptr};

    create_linked_list_head_or_node(nodeY,0);

    assign_nodeX_to_point_to_node_y(nodeX, nodeY);

    EXPECT_EQ(nodeX, nullptr);
    delete nodeY;
}

TEST(AssignNodeXToPointToNodeY, WhenNodeYHasNotBeenGivenMemory_ExpectNoChange)
{
    LinkedListNode* nodeX{nullptr};
    LinkedListNode* nodeY{nullptr};

    create_linked_list_head_or_node(nodeX,0);

    assign_nodeX_to_point_to_node_y(nodeX, nodeY);

    EXPECT_EQ(nullptr, nodeY);
    delete nodeX;
}
