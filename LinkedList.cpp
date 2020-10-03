#include "LinkedList.hpp"

int get_linked_list_length(LinkedListNode* &head)
{
    int linkedListLength{1};

    if(head == nullptr)
    {
        create_linked_list_head_or_node(head, 0);
    }

    LinkedListNode* currentNode{head};

    while(currentNode->nextNode != nullptr)
    {
        linkedListLength++;
        currentNode = currentNode->nextNode;
    }
    return linkedListLength;
}

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

void add_item_to_beginning_of_list(LinkedListNode* &head, int data)
{
    int linkedListLength{get_linked_list_length(head)};
    LinkedListNode* newNode{nullptr};
    LinkedListNode* placeHolderForOldNodes{nullptr};

    if(linkedListLength < 1)
    {
        create_linked_list_head_or_node(head, 0);
        return;
    }

        placeHolderForOldNodes = new LinkedListNode();
        placeHolderForOldNodes = head->nextNode;
        create_linked_list_head_or_node(newNode, data);
        assign_nodeX_to_point_to_node_y(head, newNode);
        assign_nodeX_to_point_to_node_y(newNode, placeHolderForOldNodes);

        return;
}

void add_item_to_end_of_list(LinkedListNode *&head, int data)
{
   int linkedListLength{get_linked_list_length(head)};
   LinkedListNode* currentNode{head};
   LinkedListNode* newNode{nullptr};

   if(linkedListLength < 1)
   {
       create_linked_list_head_or_node(head, 0);
       return;
   }
    else
   {
       while(linkedListLength > 1)
       {
           currentNode = currentNode->nextNode;
           linkedListLength--;
       }
       create_linked_list_head_or_node(newNode, data);
       assign_nodeX_to_point_to_node_y(currentNode, newNode);

       return;
   }
}

void assign_nodeX_to_point_to_node_y(LinkedListNode* &nodeX, LinkedListNode* &nodeY)
{
    if(nodeX == nullptr)
    {
        std::cout << "Error: nodeX has not been given memory yet.\n";
        return;
    }
    else if (nodeY == nullptr)
    {
        std::cout << "Error: nodeY has not been given memory yet.\n";
        return;
    }
    else
    {
        nodeX->nextNode = nodeY;
        return;
    }
}

void clear_linked_list(LinkedListNode* &head)
{
    LinkedListNode* currentNode{head};
    LinkedListNode* nxtNode{nullptr};
    int listLength{get_linked_list_length(head)};

    if(listLength < 1)
    {
        std::cout << "Error: Linked List has zero nodes. Nothing to delete. \n";
        return;
    }
    else if (listLength == 1)
    {
        head = nullptr;
    }
    else if(listLength == 2)
    {
        nxtNode = head->nextNode;
        head->nextNode = nullptr;
        head = nullptr;
        delete nxtNode;
    }
    else
    {
        currentNode = head->nextNode;

        while(listLength > 2)
        {
            nxtNode = currentNode->nextNode;
            currentNode->nextNode = nullptr;
            delete currentNode;
            currentNode = nxtNode;
            listLength--;
        }
        head = nullptr;
    }
}

void create_linked_list_head_or_node(LinkedListNode* &head, int data)
{
    head = new LinkedListNode();
    head->item = data;
}

void remove_all_instances_of_item_from_list(LinkedListNode* head, int data)
{
    int listLength{get_linked_list_length(head)};
    LinkedListNode* currentNode{head};
    LinkedListNode* nxtNode{nullptr};
    LinkedListNode* placeHolder{head};

    if(listLength < 2)
    {
        std::cout << "Error: Linked List is only a Head. Nothing to delete. \n";
        return;
    }

    listLength = get_linked_list_length(head);
    currentNode = placeHolder->nextNode;
    listLength--;

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
    if(currentNode->item == data)
    {
        placeHolder->nextNode = nullptr;
        delete currentNode;
    }
}

void remove_first_item_in_list(LinkedListNode* &head)
{
    LinkedListNode* currentNode{nullptr};
    LinkedListNode* placeHolder{nullptr};
    int listLength{get_linked_list_length(head)};

    if(listLength < 2)
    {
        std::cout << "ERROR: Error: Linked List is only a Head. Nothing to delete. \n";
    }
    else if(listLength ==2)
    {
        currentNode = head->nextNode;
        head->nextNode = nullptr;
        delete currentNode;
    }
    else
    {
        currentNode = head->nextNode;
        placeHolder = head->nextNode->nextNode;
        head->nextNode = nullptr;
        delete currentNode;
        assign_nodeX_to_point_to_node_y(head, placeHolder);
    }
    return;
}

void remove_last_item_in_list(LinkedListNode* &head)
{
    LinkedListNode* currentNode{head};
    LinkedListNode* placeHolder{nullptr};
    int listLength{get_linked_list_length(head)};

    if(listLength < 2)
    {
        std::cout << "ERROR: List is only a head. No Removal was made from list";
    }
    else if(listLength ==2)
    {
        currentNode = head->nextNode;
        head->nextNode = nullptr;
        delete currentNode;
    }
    else
    {
        while(currentNode->nextNode != nullptr)
        {
            placeHolder = currentNode;
            currentNode = currentNode->nextNode;
        }
        placeHolder->nextNode = nullptr;
        delete currentNode;
    }
    return;
}
