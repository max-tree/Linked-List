#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(AddItemToEndOfList, WhenAddingToTheEndOfAListThatDoesNotHaveAHeadWithMemory_ExpectHeadToGetMemoryAndLengthOf2)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};
    LinkedListNode* head{nullptr};

    add_item_to_end_of_list(head, 0);
    linkedListLength = get_linked_list_length(head);

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
    delete head;
}

TEST(AddItemToEndOfList, WhenAddingToTheEndOfAListThatIsJustAHead_ExpectCorrectResult)
{
    int expectedLinkedListLength = {2};
    int linkedListLength = {0};
    LinkedListNode* head{nullptr};

    create_linked_list_head_or_node(head, 0);

    add_item_to_end_of_list(head, 0);
    linkedListLength = get_linked_list_length(head);

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
     delete head;
}

TEST(AddItemToEndOfList, WhenAddingToTheEndOfAListOfLength4_ExpectLengthOfListToIncreaseByOne)
{
    int expectedLinkedListLength = {4};
    int linkedListLength = {0};
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 0);
    create_linked_list_head_or_node(third, 0);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);

    add_item_to_end_of_list(head, 0);
    linkedListLength = get_linked_list_length(head);

    EXPECT_EQ(expectedLinkedListLength, linkedListLength);
     delete head;
}
