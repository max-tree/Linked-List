#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>

struct LinkedListNode
{
    double item{0};
    LinkedListNode* nextNode{nullptr};
};

class LinkedList
{
    //Private data should be at the bottom of the class.
    //The users of this class wants to see the public function first.
private:
    double item{0};
    LinkedListNode* head;
public:

    LinkedList();
    ~LinkedList();
    int get_linked_list_length();
    std::string convert_linked_list_to_string();
    void add_item_to_beginning_of_list(int data);
    void add_item_to_end_of_list(int data);
    //This function isn't any use to a user.  They shouldn't have to know or worry about the LinkedListNode
    void assign_head_to_point_to_node_y(LinkedListNode* &nodeY);
    void clear_linked_list();
    //Same here
    void create_linked_list_head(int data);
    void remove_all_instances_of_item_from_list(int data);
    void remove_first_item_in_list();
    void remove_last_item_in_list();

    //And these also.
    LinkedListNode* getHeadAddress();
    double getHeadItem();

    //As we talked in class these "internal" function should be in a separate file that can be used but doesn't need to be
    //available to the users.

};

//These should be in a separate file.
namespace LLN
{
void create_linked_list_node(LinkedListNode* &newNode, int data);
void assign_nodeX_to_point_to_node_y(LinkedListNode* &nodeX, LinkedListNode* &nodeY);
}

#endif
