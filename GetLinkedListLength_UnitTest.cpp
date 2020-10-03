#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(LinkedListLength, WhenListIsJustTheHead_Expect1)
{
    int expectedLinkedListLength{1};
    LinkedListNode* head{nullptr};
    create_linked_list_head_or_node(head,0);

    EXPECT_EQ(expectedLinkedListLength, get_linked_list_length(head));
    delete head;
}

TEST(LinkedListLength, WhenListIsMissingTheHeadMemory_ExpectHeadMemoryCreationAnd1)
{
    int expectedLinkedListLength{1};
    LinkedListNode* head{nullptr};

    EXPECT_EQ(expectedLinkedListLength, get_linked_list_length(head));
    delete head;
}

TEST(LinkedListLength, WhenListIsTheHeadAndTwoNodes_Expect3)
{
    int expectedLinkedListLength{3};
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    create_linked_list_head_or_node(head,0);
    create_linked_list_head_or_node(second,0);
    create_linked_list_head_or_node(third,0);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);

    EXPECT_EQ(expectedLinkedListLength, get_linked_list_length(head));
    delete head;
}
