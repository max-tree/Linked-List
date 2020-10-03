#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithNo1s_ExpectNoChange)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 2);
    create_linked_list_head_or_node(third, 2);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);

    remove_all_instances_of_item_from_list(head, 1);
    std::string expectedResult{"(2 2)"};

    EXPECT_EQ(expectedResult, convert_linked_list_to_string(head));
}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithOne1_Expect1Removed)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 1);
    create_linked_list_head_or_node(third, 2);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);

    remove_all_instances_of_item_from_list(head, 1);
    std::string expectedResult{"(2)"};

    EXPECT_EQ(expectedResult, convert_linked_list_to_string(head));
}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithOneNodeWithAnItemOf1_ExpectOnlyHead)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 1);

    assign_nodeX_to_point_to_node_y(head, second);

    remove_all_instances_of_item_from_list(head, 1);
    std::string expectedResult{"()"};

    EXPECT_EQ(expectedResult, convert_linked_list_to_string(head));

}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromListWithAll1s_ExpectOnlyHead)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};
    LinkedListNode* fourth{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 1);
    create_linked_list_head_or_node(third, 1);
    create_linked_list_head_or_node(fourth, 1);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);
    assign_nodeX_to_point_to_node_y(third, fourth);

    remove_all_instances_of_item_from_list(head, 1);
    std::string expectedResult{"()"};

    EXPECT_EQ(expectedResult, convert_linked_list_to_string(head));
}

TEST(RemoveAllInstancesOfItemFromList, WhenRemoving1FromList_ExpectListWithoutOnes)
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

    remove_all_instances_of_item_from_list(head, 1);
    std::string expectedResult{"(4 2)"};

    EXPECT_EQ(expectedResult, convert_linked_list_to_string(head));
}
