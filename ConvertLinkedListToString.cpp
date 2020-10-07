#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(ConvertLinkedListToString, WhenLinkedListIsOnlyAHead_ExpectNothing)
{
    LinkedList linkedList;
    std::string result{"()"};

    linkedList.create_linked_list_head(0);

    EXPECT_EQ(result,linkedList.convert_linked_list_to_string());

}

TEST(ConvertLinkedListToString, WhenLinkedListIsOneNodeLong_ExpectOneNumber)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 1);//for second????????????????????

    linkedList.assign_head_to_point_to_node_y(second);

    EXPECT_EQ("(1)", linkedList.convert_linked_list_to_string());
}
TEST(ConvertLinkedListToString, WhenLinkedListIsTwoNodesLong_ExpectTwoNumbers)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 1);
    LLN::create_linked_list_node(third, 2);

    linkedList.assign_head_to_point_to_node_y(second);
    LLN::assign_nodeX_to_point_to_node_y(second, third);

    EXPECT_EQ("(1 2)", linkedList.convert_linked_list_to_string());
}
