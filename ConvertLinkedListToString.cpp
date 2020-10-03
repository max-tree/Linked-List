#include "LinkedList.hpp"
#include "gtest/gtest.h"

std::string convert_linked_list_to_string(LinkedListNode* head)
{
    std::string listToString{NULL};
    int listLength{get_linked_list_length(head)};
    LinkedListNode* currentNode{nullptr};
    currentNode = head;
    listToString.pop_back();
    listToString.push_back('(');
    if(listLength > 1)
    {
        while(listLength > 1)
        {
            currentNode = currentNode->nextNode;
            listToString.push_back(currentNode->item + '0');
            listToString.push_back(' ');
            listLength--;
        }
        listToString.pop_back();
    }
    listToString.push_back(')');
    return listToString;

}

TEST(ConvertLinkedListToString, WhenLinkedListIsOnlyAHead_ExpectNothing)
{
    LinkedListNode* head{nullptr};
    create_linked_list_head_or_node(head, 0);
    std::string result{"()"};
    EXPECT_EQ(result,convert_linked_list_to_string(head));

}

TEST(ConvertLinkedListToString, WhenLinkedListIsOneNodeLong_ExpectOneNumber)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 1);

    assign_nodeX_to_point_to_node_y(head, second);

    EXPECT_EQ("(1)", convert_linked_list_to_string(head));
}
TEST(ConvertLinkedListToString, WhenLinkedListIsTwoNodesLong_ExpectTwoNumbers)
{
    LinkedListNode* head{nullptr};
    LinkedListNode* second{nullptr};
    LinkedListNode* third{nullptr};

    create_linked_list_head_or_node(head, 0);
    create_linked_list_head_or_node(second, 1);
    create_linked_list_head_or_node(third, 2);

    assign_nodeX_to_point_to_node_y(head, second);
    assign_nodeX_to_point_to_node_y(second, third);

    EXPECT_EQ("(1 2)", convert_linked_list_to_string(head));
}
