#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(RemoveFirstItemInList, WhenListIsOnlyHead_ExpectNoChangeAndErrorMessage)
{
    LinkedList linkedList;

    linkedList.remove_first_item_in_list();

    int listLength{linkedList.get_linked_list_length()};
    int expectedResult{1};

    EXPECT_EQ(listLength, expectedResult);
}

TEST(RemoveFirstItemInList, WhenListHasOneNode_ExpectOnlyHead)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 0);

    linkedList.assign_head_to_point_to_node_y(second);
    linkedList.remove_first_item_in_list();
    int listLength{linkedList.get_linked_list_length()};
    int expectedResult{1};

    EXPECT_EQ(listLength, expectedResult);
}

TEST(RemoveFirstItemInList, WhenListIslong_ExpectLengthToDecreaseByOne)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};
    LinkedListNode* fourth{nullptr};
    LinkedListNode* fifth{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 4);
    LLN::create_linked_list_node(third, 1);
    LLN::create_linked_list_node(fourth, 1);
    LLN::create_linked_list_node(fifth, 2);

    linkedList.assign_head_to_point_to_node_y(second);
    LLN::assign_nodeX_to_point_to_node_y(second, third);
    LLN::assign_nodeX_to_point_to_node_y(third, fourth);
    LLN::assign_nodeX_to_point_to_node_y(fourth, fifth);

    linkedList.remove_first_item_in_list();
    int listLength{linkedList.get_linked_list_length()};
    int expectedResult{4};

    EXPECT_EQ(listLength, expectedResult);
}
