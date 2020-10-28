#include "LinkedList.hpp"
#include "gtest/gtest.h"
//Be sure to remove code duplication.

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithNo1s_ExpectNoChange)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 2);
    LLN::create_linked_list_node(third, 2);

    linkedList.assign_head_to_point_to_node_y(second);
    LLN::assign_nodeX_to_point_to_node_y(second, third);

    linkedList.remove_all_instances_of_item_from_list(1);
    std::string expectedResult{"(2 2)"};

    EXPECT_EQ(expectedResult, linkedList.convert_linked_list_to_string());
}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithOne1_Expect1Removed)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 1);
    LLN::create_linked_list_node(third, 2);

    linkedList.assign_head_to_point_to_node_y(second);
    LLN::assign_nodeX_to_point_to_node_y(second, third);

    linkedList.remove_all_instances_of_item_from_list(1);
    std::string expectedResult{"(2)"};

    EXPECT_EQ(expectedResult, linkedList.convert_linked_list_to_string());
}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithOneNodeWithAnItemOf1_ExpectOnlyHead)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 1);

    linkedList.assign_head_to_point_to_node_y(second);

    linkedList.remove_all_instances_of_item_from_list(1);
    std::string expectedResult{"()"};

    EXPECT_EQ(expectedResult, linkedList.convert_linked_list_to_string());

}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithAll1s_ExpectOnlyHead)
{
    LinkedList linkedList;
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};
    LinkedListNode* fourth{nullptr};

    linkedList.create_linked_list_head(0);
    LLN::create_linked_list_node(second, 1);
    LLN::create_linked_list_node(third, 1);
    LLN::create_linked_list_node(fourth, 1);

    linkedList.assign_head_to_point_to_node_y(second);
    LLN::assign_nodeX_to_point_to_node_y(second, third);
    LLN::assign_nodeX_to_point_to_node_y(third, fourth);

    linkedList.remove_all_instances_of_item_from_list(1);
    std::string expectedResult{"()"};

    EXPECT_EQ(expectedResult, linkedList.convert_linked_list_to_string());
}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromList_ExpectListWithoutOnes)
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

    linkedList.remove_all_instances_of_item_from_list(1);
    std::string expectedResult{"(4 2)"};

    EXPECT_EQ(expectedResult, linkedList.convert_linked_list_to_string());
}
