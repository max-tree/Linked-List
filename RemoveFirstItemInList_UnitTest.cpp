#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(RemoveFirstItemInList, WhenListIsOnlyHead_ExpectNoChangeAndErrorMessage)
{
    LinkedListNode* head{nullptr};

    remove_first_item_in_list(head);

    int listLength{get_linked_list_length(head)};
    int expectedResult{1};

    EXPECT_EQ(listLength, expectedResult);
}

TEST(RemoveFirstItemInList, WhenListHasOneNode_ExpectOnlyHead)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 0);

    assign_nodeX_to_point_to_node_y(head, second);
    remove_first_item_in_list(head);
    int listLength{get_linked_list_length(head)};
    int expectedResult{1};

    EXPECT_EQ(listLength, expectedResult);
}

TEST(RemoveFirstItemInList, WhenListIslong_ExpectLengthToDecreaseByOne)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};
    LinkedListNode* fourth{nullptr};
    LinkedListNode* fifth{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 4);
    create_linked_list_head_or_node(third, 1);
    create_linked_list_head_or_node(fourth, 1);
    create_linked_list_head_or_node(fifth, 2);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);
    assign_nodeX_to_point_to_node_y(third, fourth);
    assign_nodeX_to_point_to_node_y(fourth, fifth);

    remove_first_item_in_list(head);
    int listLength{get_linked_list_length(head)};
    int expectedResult{4};

    EXPECT_EQ(listLength, expectedResult);
}
