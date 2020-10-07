#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithNoMemory_ExpectListLengthOfZero)
{
    LinkedList linkedList;
    LinkedListNode* expectedResult{nullptr};

    linkedList.clear_linked_list();

    EXPECT_EQ(expectedResult, linkedList.getHeadAddress());
}

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithMemory_ExpectListLengthOfZero)
{
    LinkedList linkedList;
    LinkedListNode* expectedResult{nullptr};

    linkedList.create_linked_list_head(0);
    linkedList.clear_linked_list();

    EXPECT_EQ(expectedResult, linkedList.getHeadAddress());
}

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithOneNode_ExpectListLengthOfZero)
{
    LinkedList linkedList;
    LinkedListNode* expectedResult{nullptr};

    linkedList.create_linked_list_head(0);
    linkedList.clear_linked_list();

    EXPECT_EQ(expectedResult, linkedList.getHeadAddress());
}
