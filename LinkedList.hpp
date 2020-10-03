#ifndef MYLIBRARY_HPP
#define MYLIBRARY_HPP

#include <iostream>
#include <string>

struct LinkedListNode
{
    double item{0};
    LinkedListNode* nextNode{nullptr};
};


void create_linked_list_head_or_node(LinkedListNode* &head, int data);
void add_item_to_end_of_list(LinkedListNode *&head, int data);
int get_linked_list_length(LinkedListNode* &head);
void assign_nodeX_to_point_to_node_y(LinkedListNode* &nodeX, LinkedListNode* &nodeY);
void add_item_to_beginning_of_list(LinkedListNode* &head, int data);
std::string convert_linked_list_to_string(LinkedListNode* head);
void clear_linked_list(LinkedListNode* &head);




#endif
