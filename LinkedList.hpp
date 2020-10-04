#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>

struct LinkedListNode
{
    double item{0};
    LinkedListNode* nextNode{nullptr};
};

int get_linked_list_length(LinkedListNode* &head);
std::string convert_linked_list_to_string(LinkedListNode* head);
void add_item_to_beginning_of_list(LinkedListNode* &head, int data);
void add_item_to_end_of_list(LinkedListNode *&head, int data);
void assign_nodeX_to_point_to_node_y(LinkedListNode* &nodeX, LinkedListNode* &nodeY);
void clear_linked_list(LinkedListNode* &head);
void create_linked_list_head_or_node(LinkedListNode* &head, int data);
void remove_all_instances_of_item_from_list(LinkedListNode* head, int data);
void remove_first_item_in_list(LinkedListNode* &head);
void remove_last_item_in_list(LinkedListNode* &head);

#endif
