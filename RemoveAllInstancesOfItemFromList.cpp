#include "LinkedList.hpp"
#include "gtest/gtest.h"



//I think something is not initialized because I get random results coming out of the third test on this page.

void remove_all_instances_of_item_from_list(LinkedListNode* head, int data)
{
    int listLength{get_linked_list_length(head)};
    if(listLength < 1)
    {
        std::cout << "Error: Linked List has zero nodes. Nothing to delete. \n";
        return;
    }
    LinkedListNode* currentNode{head};
    LinkedListNode* nxtNode{nullptr};
    LinkedListNode* placeHolder{head};
    listLength = get_linked_list_length(head);
    while(listLength > 1)
    {
        nxtNode = currentNode->nextNode;
        if(currentNode->item == data)
        {
            delete currentNode;
            assign_nodeX_to_point_to_node_y(placeHolder, nxtNode);
        }
        else
        {
            placeHolder = currentNode;
        }
        currentNode = nxtNode;
        listLength--;
    }
    currentNode = head->nextNode;
    if(currentNode->item == 1)
    {

        delete currentNode;

    }
}

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
