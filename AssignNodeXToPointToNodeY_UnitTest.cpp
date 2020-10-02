#include "LinkedList.hpp"
#include "gtest/gtest.h"

void assign_nodeX_to_point_to_node_y(LinkedListNode* &nodeX, LinkedListNode* &nodeY)
{
    if(nodeX == nullptr)
    {
        std::cout << "Error: nodeX has not been given memory yet.\n";
        return;
    }
    else if (nodeY == nullptr)
    {
        std::cout << "Error: nodeY has not been given memory yet.\n";
        return;
    }
    else
    {
    nodeX->nextNode = nodeY;
    return;
    }
}

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
