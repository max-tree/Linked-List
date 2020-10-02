#include "LinkedList.hpp"
#include "gtest/gtest.h"

std::array <char, 10> convert_linked_list_to_string(LinkedListNode* head)
{
//    std::array <char, 10> listToString{" "," "," "," "," "," "," "," "};
}

TEST(ConvertLinkedListToString, WhenLinkedListIsOnlyAHead_ExpectNothing)
{
    LinkedListNode* head{nullptr};
    create_linked_list_head_or_node(head, 0);
//    EXPECT_STREQ(convert_linked_list_to_string(head), "");

}

//TEST(ConvertLinkedListToString, WhenLinkedListIsOnlyAHead_ExpectNothing)
//{
//    LinkedListNode* head{nullptr};
//    LinkedListNode* second{nullptr};
//    LinkedListNode* third{nullptr};

//    create_linked_list_head_or_node(head, 0);
//    create_linked_list_head_or_node(second, 1);
//    create_linked_list_head_or_node(third, 2);

//    assign_nodeX_to_point_to_node_y(head, second);
//    assign_nodeX_to_point_to_node_y(second, third);
//}
