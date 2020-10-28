#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    clear_linked_list();
}

int LinkedList::get_linked_list_length()
{
    int linkedListLength{1};

    if(head == nullptr)
    {
        //So asking the length creates an item in the list?
        create_linked_list_head(0);
    }

    LinkedListNode* currentNode{head};

    while(currentNode->nextNode != nullptr)
    {
        linkedListLength++;
        currentNode = currentNode->nextNode;
    }
    return linkedListLength;
}

std::string LinkedList::convert_linked_list_to_string()
{
    std::string listToString{NULL};
    int listLength{get_linked_list_length()};
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

void LinkedList::add_item_to_beginning_of_list(int data)
{
    int linkedListLength{get_linked_list_length()};
    LinkedListNode* newNode{nullptr};
    LinkedListNode* placeHolderForOldNodes{nullptr};

    if(linkedListLength < 1)
    {
        create_linked_list_head(0);
        return;
    }

        placeHolderForOldNodes = new LinkedListNode();
        placeHolderForOldNodes = head->nextNode;
        LLN::create_linked_list_node(newNode, data);
        assign_head_to_point_to_node_y(newNode);
        LLN::assign_nodeX_to_point_to_node_y(newNode, placeHolderForOldNodes);

        return;
}

void LinkedList::add_item_to_end_of_list(int data)
{
   int linkedListLength{get_linked_list_length()};
   LinkedListNode* currentNode{head};
   LinkedListNode* newNode{nullptr};

   if(linkedListLength < 1)
   {
       create_linked_list_head(0);
       return;
   }
    else
   {
       while(linkedListLength > 1)
       {
           currentNode = currentNode->nextNode;
           linkedListLength--;
       }
       LLN::create_linked_list_node(newNode, data);
       LLN::assign_nodeX_to_point_to_node_y(currentNode, newNode);

       return;
   }
}

void LinkedList::assign_head_to_point_to_node_y(LinkedListNode* &nodeY)
{
    //It is best practice to not print out warnings.  It is better to return
    //the warning and let the user decide what to do with it.  If this was used in
    //Microsoft Word what would you as the user think of this warning?  It wouldn't make
    //any sense.
    if(head == nullptr)
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
        head->nextNode = nodeY;
        return;
    }
}


void LinkedList::clear_linked_list()
{
    LinkedListNode* currentNode{head};
    LinkedListNode* nxtNode{nullptr};
    int listLength{get_linked_list_length()};

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

void LinkedList::create_linked_list_head(int data)
{
    head = new LinkedListNode();
    item = data;
}


void LinkedList::remove_all_instances_of_item_from_list(int data)
{
    int listLength{get_linked_list_length()};
    LinkedListNode* currentNode{head};
    LinkedListNode* nxtNode{nullptr};
    LinkedListNode* placeHolder{head};

    if(listLength < 2)
    {
        std::cout << "Error: Linked List is only a Head. Nothing to delete. \n";
        return;
    }

    listLength = get_linked_list_length();
    currentNode = placeHolder->nextNode;
    listLength--;

    while(listLength > 1)
    {
        nxtNode = currentNode->nextNode;

        if(currentNode->item == data)
        {
            delete currentNode;
            LLN::assign_nodeX_to_point_to_node_y(placeHolder, nxtNode);
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

void LinkedList::remove_first_item_in_list()
{
    LinkedListNode* currentNode{nullptr};
    LinkedListNode* placeHolder{nullptr};
    int listLength{get_linked_list_length()};

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
        assign_head_to_point_to_node_y(placeHolder);
    }
    return;
}

void LinkedList::remove_last_item_in_list()
{
    LinkedListNode* currentNode{head};
    LinkedListNode* placeHolder{nullptr};
    int listLength{get_linked_list_length()};

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

LinkedListNode* LinkedList::getHeadAddress()
{return head;}

double LinkedList::getHeadItem()
{return item;}

namespace LLN
{
    void create_linked_list_node(LinkedListNode* &newNode, int data)
    {
        newNode = new LinkedListNode();
        newNode->item = data;
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
}
