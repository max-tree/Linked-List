#include "LinkedList.hpp"
#include "gtest/gtest.h"

//There is some code duplication that should be removed.
TEST(AddItemToEndOfList, WhenAddingToTheEndOfAListThatDoesNotHaveAHeadWithMemory_ExpectHeadToGetMemoryAndLengthOf2)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};
    LinkedList linkedList;

    linkedList.add_item_to_end_of_list(0);
    linkedListLength = linkedList.get_linked_list_length();

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    linkedList.~LinkedList();
}

TEST(AddItemToEndOfList, WhenAddingToTheEndOfAListThatIsJustAHead_ExpectCorrectResult)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};
    LinkedList linkedList;

    linkedList.create_linked_list_head(0);

    linkedList.add_item_to_end_of_list(0);
    linkedListLength = linkedList.get_linked_list_length();

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    linkedList.~LinkedList();
}

TEST(AddItemToEndOfList, WhenAddingToTheEndOfAListOfLength4_ExpectLengthOfListToIncreaseByOne)
{
    int expectedLinkedListLength = {4};
    int linkedListLength = {0};
    LinkedList linkedList;
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 0);
    LLN::create_linked_list_node(third, 0);

    linkedList.assign_head_to_point_to_node_y(second);
    LLN::assign_nodeX_to_point_to_node_y(second, third);

    linkedList.add_item_to_end_of_list(0);
    linkedListLength = linkedList.get_linked_list_length();

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    linkedList.~LinkedList();
}
