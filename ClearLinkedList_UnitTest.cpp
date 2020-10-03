#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithNoMemory_ExpectListLengthOfZero)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* expectedResult{nullptr};

    clear_linked_list(head);

    EXPECT_EQ(expectedResult, head);
}

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithMemory_ExpectListLengthOfZero)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* expectedResult{nullptr};

    create_linked_list_head_or_node(head, 0);
    clear_linked_list(head);

    EXPECT_EQ(expectedResult, head);
}

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithOneNode_ExpectListLengthOfZero)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* expectedResult{nullptr};

    create_linked_list_head_or_node(head, 0);
    clear_linked_list(head);

    EXPECT_EQ(expectedResult, head);
}
