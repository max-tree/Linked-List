#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(CreateLinkedListHead, WhenHeadIsNullAndItemIs0_ExpectCorrectOutput)
{
    LinkedListNode* expectedResult{nullptr};
    LinkedList linkedList;
    double tolerance = 0.001;

    expectedResult = new LinkedListNode();
    expectedResult->item = 0;
    expectedResult->nextNode = nullptr;
    linkedList.create_linked_list_head(0);

    EXPECT_NE(nullptr, linkedList.getHeadAddress());
    EXPECT_NEAR(expectedResult->item, linkedList.getHeadItem(), tolerance);
    linkedList.~LinkedList();
    delete expectedResult;
}

TEST(CreateLinkedListHead, WhenHeadIsNullAndItemIs10_ExpectCorrectOutput)
{
    LinkedListNode* expectedResult{nullptr};
    LinkedList linkedList;
    double tolerance = 0.001;

    expectedResult = new LinkedListNode();
    expectedResult->item = 10;
    linkedList.create_linked_list_head(10);

    EXPECT_NEAR(expectedResult->item, linkedList.getHeadItem(), tolerance);
    linkedList.~LinkedList();
    delete expectedResult;
}
