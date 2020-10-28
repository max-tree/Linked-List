#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(AddItemToBeginningOfList, WhenAddingToTheBeginningOfAListThatDoesNotHaveAHeadWithMemory_ExpectHeadToGetMemoryAndLengthOf2)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};
    LinkedList linkedList;
    linkedList.add_item_to_beginning_of_list(0);
    linkedListLength = linkedList.get_linked_list_length();
//Adding one number should result in a length of 1.
    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
}

TEST(AddItemToBeginningOfList, WhenAddingToTheBeginningOfAListThatHasAHeadWithMemory_ExpectListLengthToIncreaseByOne)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};
    LinkedList linkedList;

    linkedList.create_linked_list_head(0);

    linkedList.add_item_to_beginning_of_list(0);
    linkedListLength = linkedList.get_linked_list_length();

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    linkedList.~LinkedList();
}

TEST(AddItemToBeginningOfList, WhenAddingToTheBeginningOfAListWithANode_ExpectListLengthToIncreaseByOne)
{
    int expectedLinkedListLength = {3};
    int linkedListLength = {0};

    LinkedList linkedList;
    LinkedListNode* nodeX{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(nodeX, 0);

    linkedList.assign_head_to_point_to_node_y(nodeX);//How can I fix this? I want to be able to pass either the head of any LinkedListNode

    linkedList.add_item_to_beginning_of_list(0);
    linkedListLength = linkedList.get_linked_list_length();

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    linkedList.~LinkedList();
    delete nodeX;
}
