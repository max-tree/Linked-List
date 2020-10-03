#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(ConvertLinkedListToString, WhenLinkedListIsOnlyAHead_ExpectNothing)
{
    LinkedListNode* head{nullptr};
    std::string result{"()"};

    create_linked_list_head_or_node(head, 0);

    EXPECT_EQ(result,convert_linked_list_to_string(head));

}

TEST(ConvertLinkedListToString, WhenLinkedListIsOneNodeLong_ExpectOneNumber)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 1);

    assign_nodeX_to_point_to_node_y(head, second);

    EXPECT_EQ("(1)", convert_linked_list_to_string(head));
}
TEST(ConvertLinkedListToString, WhenLinkedListIsTwoNodesLong_ExpectTwoNumbers)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 1);
    create_linked_list_head_or_node(third, 2);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);

    EXPECT_EQ("(1 2)", convert_linked_list_to_string(head));
}
