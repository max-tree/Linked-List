#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(CreateLinkedListHead, WhenHeadIsNullAndItemIs0_ExpectCorrectOutput)
{
    LinkedListNode* expectedResult{nullptr};
    LinkedListNode* head{nullptr};
    double tolerance = 0.001;

    expectedResult = new LinkedListNode();
    expectedResult->item = 0;
    expectedResult->nextNode = nullptr;
    create_linked_list_head_or_node(head,0);

    EXPECT_NE(nullptr, head);
    EXPECT_NEAR(expectedResult->item, head->item, tolerance);
    delete head;
    delete expectedResult;
}

TEST(CreateLinkedListHead, WhenHeadIsNullAndItemIs10_ExpectCorrectOutput)
{
    LinkedListNode* expectedResult{nullptr};
    LinkedListNode* head{nullptr};
    double tolerance = 0.001;

    expectedResult = new LinkedListNode();
    expectedResult->item = 10;
    create_linked_list_head_or_node(head,10);

    EXPECT_NEAR(expectedResult->item, head->item, tolerance);
    delete head;
    delete expectedResult;
}
