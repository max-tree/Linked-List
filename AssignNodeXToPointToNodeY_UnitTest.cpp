#include "LinkedList.hpp"
#include "gtest/gtest.h"

void assign_nodeX_to_point_to_node_y(LinkedListNode* &nodeX, LinkedListNode* &nodeY)
{
    nodeX->nextNode = nodeY;
}

//TEST(AssignNodeXToPointToNodeY, WhenNodeXPointsToNodeY_ExpectCorrectResult)
//{
//    LinkedListNode* nodeX{nullptr};
//    LinkedListNode* nodeY{nullptr};
//    create_linked_list_head_or_node(nodeX,0);
//    create_linked_list_head_or_node(nodeY,0);
//    assign_nodeX_to_point_to_node_y(nodeX, nodeY);
//    EXPECT_EQ(nodeX->nextNode, nodeY);
//    delete nodeX;
//    delete nodeY;
//}
