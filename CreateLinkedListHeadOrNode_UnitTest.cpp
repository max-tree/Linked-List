#include "LinkedList.hpp"
#include "gtest/gtest.h"

void create_linked_list_head_or_node(LinkedListNode* &head, int data)
{
    head = new LinkedListNode();
    head->item = data;
}

TEST(CreateLinkedListHead, WhenHeadIsNullAndItemIs0_ExpectCorrectOutput)
{
    LinkedListNode* expectedResult{nullptr};
    expectedResult = new LinkedListNode();
    expectedResult->item = 0;
    expectedResult->nextNode = nullptr;
    double tolerance = 0.001;
    LinkedListNode* head{nullptr};
    create_linked_list_head_or_node(head,0);
    EXPECT_NE(nullptr, head);
    EXPECT_NEAR(expectedResult->item, head->item, tolerance);
    delete head;
    delete expectedResult;
}

TEST(CreateLinkedListHead, WhenHeadIsNullAndItemIs10_ExpectCorrectOutput)
{
    LinkedListNode* expectedResult{nullptr};
    expectedResult = new LinkedListNode();
    expectedResult->item = 10;
    LinkedListNode* head{nullptr};
    double tolerance = 0.001;
    create_linked_list_head_or_node(head,10);
    EXPECT_NEAR(expectedResult->item, head->item, tolerance);
    delete head;
    delete expectedResult;
}
