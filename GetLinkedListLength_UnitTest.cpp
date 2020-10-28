#include "LinkedList.hpp"
#include "gtest/gtest.h"
//I like that you are thinking about the logic in you functions.
//These are good tests.  Some improvement could be made in separating the
//user facing functions with the internal functions.  The user doesn't care about
//Memory, heads, and a list with a head or with out one.  They just want to add some numbers
//to a list and the size should just tell them how many numbers are in the list.
TEST(LinkedListLength, WhenListIsJustTheHead_Expect1)
{
    int expectedLinkedListLength{1};
    LinkedList linkedList;
    linkedList.create_linked_list_head(0);

    EXPECT_EQ(expectedLinkedListLength, linkedList.get_linked_list_length());
    //Shouldn't an empty list return 0?

    //You don't need to call the constructor.  It is called automatically when linkedList
    //goes out of scope.
    linkedList.~LinkedList();
}

TEST(LinkedListLength, WhenListIsMissingTheHeadMemory_ExpectHeadMemoryCreationAnd1)
{
    int expectedLinkedListLength{1};
    LinkedList linkedList;

    EXPECT_EQ(expectedLinkedListLength, linkedList.get_linked_list_length());
    linkedList.~LinkedList();
}

TEST(LinkedListLength, WhenListIsTheHeadAndTwoNodes_Expect3)
{
    int expectedLinkedListLength{3};
    LinkedList linkedList;
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 0);
    LLN::create_linked_list_node(third, 0);

    linkedList.assign_head_to_point_to_node_y(second);
    LLN::assign_nodeX_to_point_to_node_y(second, third);

    EXPECT_EQ(expectedLinkedListLength, linkedList.get_linked_list_length());
    linkedList.~LinkedList();
}
