#ifndef MYLIBRARY_HPP
#define MYLIBRARY_HPP

#include <iostream>


struct LinkedListNode
{
    double item{0};
    LinkedListNode* nextNode{nullptr};
};


void create_linked_list_head_or_node(LinkedListNode* &head, int data);
void add_item_to_end_of_linked_list(LinkedListNode *&head, int data);
int get_linked_list_length(LinkedListNode* head);
void assign_nodeX_to_point_to_node_y(LinkedListNode* &nodeX, LinkedListNode* &nodeY);


#endif
