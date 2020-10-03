#include "LinkedList.hpp"
#include "gtest/gtest.h"

void clear_linked_list(LinkedListNode* &head)
{
    int listLength{get_linked_list_length(head)};
    if(listLength < 1)
    {
        std::cout << "Error: Linked List has zero nodes. Nothing to delete. \n";
        return;
    }
    LinkedListNode* currentNode{head};
    LinkedListNode* nxtNode{nullptr};
    listLength = get_linked_list_length(head);
    while(listLength > 1)
    {
        nxtNode = currentNode->nextNode;
        delete currentNode;
        currentNode = nxtNode;
        listLength--;
    }
}

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithNoMemory_ExpectListLengthOfZero)
{
    LinkedListNode* head{nullptr};
    clear_linked_list(head);
    LinkedListNode* expectedResult{nullptr};
    EXPECT_NE(expectedResult, head);
}

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithMemory_ExpectListLengthOfZero)
{
    LinkedListNode* head{nullptr};
    create_linked_list_head_or_node(head, 0);
    clear_linked_list(head);
    LinkedListNode* expectedResult{nullptr};
    EXPECT_NE(expectedResult, head);
}

TEST(ClearLinkedList, WhenLinkedListIsAHeadWithOneNode_ExpectListLengthOfZero)
{
    LinkedListNode* head{nullptr};
    create_linked_list_head_or_node(head, 0);
    clear_linked_list(head);
    LinkedListNode* expectedResult{nullptr};
    EXPECT_NE(expectedResult, head);
}
