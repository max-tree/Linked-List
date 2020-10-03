#include "LinkedList.hpp"
#include "gtest/gtest.h"

void add_item_to_beginning_of_list(LinkedListNode* &head, int data)
{
    int linkedListLength{get_linked_list_length(head)};
    if(linkedListLength < 1)
    {
        create_linked_list_head_or_node(head, 0);
        return;
    }

        LinkedListNode* placeHolderForOldNodes{nullptr};
        placeHolderForOldNodes = new LinkedListNode();
        placeHolderForOldNodes = head->nextNode;
        LinkedListNode* newNode{nullptr};
        create_linked_list_head_or_node(newNode, data);
        assign_nodeX_to_point_to_node_y(head, newNode);
        assign_nodeX_to_point_to_node_y(newNode, placeHolderForOldNodes);
        return;
}

TEST(AddItemToBeginningOfList, WhenAddingToTheBeginningOfAListThatDoesNotHaveAHeadWithMemory_ExpectHeadToGetMemoryAndLengthOf2)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};

    LinkedListNode* head{nullptr};
    add_item_to_beginning_of_list(head, 0);
    linkedListLength = get_linked_list_length(head);
    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
}

TEST(AddItemToBeginningOfList, WhenAddingToTheBeginningOfAListThatHasAHeadWithMemory_ExpectListLengthToIncreaseByOne)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};

    LinkedListNode* head{nullptr};
    create_linked_list_head_or_node(head, 0);
    add_item_to_beginning_of_list(head, 0);
    linkedListLength = get_linked_list_length(head);
    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    delete head;
}

TEST(AddItemToBeginningOfList, WhenAddingToTheBeginningOfAListWithANode_ExpectListLengthToIncreaseByOne)
{
    int expectedLinkedListLength = {3};
    int linkedListLength = {0};

    LinkedListNode* head{nullptr};
    LinkedListNode* nodeX{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(nodeX, 0);

    assign_nodeX_to_point_to_node_y(head, nodeX);

    add_item_to_beginning_of_list(head, 0);
    linkedListLength = get_linked_list_length(head);

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    delete head;
    delete nodeX;
}
