#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
}

bool LinkedList::isEmpty()
{
    //List is empty if head is pointing to NULL
    return head == NULL;
}

void LinkedList::insert(int data)
{
    // Check for empty list
    if (isEmpty())
    {
        //set head pointing to new node
        head = _newNode(data);
        return;
    }
    Node *current = head;

    //Iterate till last element
    while (current->nextNode != NULL)
    {
        current = current->nextNode;
    }
    current->nextNode = _newNode(data);
}

void LinkedList::insertAt(int pos, int data)
{
    // At pos = 0
    if (pos == 0)
    {
        Node *newNode = _newNode(data);
        newNode->nextNode = head;
        head = newNode;
        return;
    }
    int index = 0;
    Node *current = head;
    //Iterate upto the previous position
    if (pos > 0 && pos <= size())
    {
        while (index < pos - 1 && current != NULL)
        {
            current = current->nextNode;
            index++;
        }
        Node *newNode = _newNode(data);
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    else
    {
        cout << "Invalid position" << endl;
    }
}

void LinkedList::remove(int data)
{
    //Check for empty list
    if (isEmpty())
    {
        cout << "List is Empty!" << endl;
        return;
    }

    //Check for list containing only one Node
    if (head->nextNode == NULL)
    {
        if (head->data == data)
        {
            delete head;
            head = NULL;
        }
        return;
    }

    //Check for element found at head
    Node *current = head;
    if (current->data == data)
    {
        head = current->nextNode;
        delete current;
        return;
    }

    //Iterate upto the previous element
    while (current->nextNode != NULL && current->nextNode->data != data)
    {
        current = current->nextNode;
    }

    if (current->nextNode != NULL && current->nextNode->data == data)
    {
        Node *temp = current->nextNode;
        current->nextNode = temp->nextNode;
        delete temp;
        return;
    }
    cout << "Not Found!" << endl;
}

void LinkedList::removeAt(int pos)
{
    // Check list is empty
    if (isEmpty())
    {
        cout << "List is Empty" << endl;
        return;
    }
    //At pos = 0
    if (pos == 0)
    {
        Node *temp = head;
        head = head->nextNode;
        delete temp;
    }
    //Iterate upto the previous position's element
    if (pos <= size())
    {
        int index = 0;
        Node *current = head;
        while (index < pos - 1)
        {
            current = current->nextNode;
            index++;
        }
        Node *temp = current->nextNode;
        current->nextNode = temp->nextNode;
        delete temp;
    }
    else
    {
        cout << "Invalid position" << endl;
    }
}

void LinkedList::traverse()
{
    // Check for empty list
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *current = head;
    //do ..while(condition) is required, as we want to print 1st element also
    do
    {
        cout << current->data << " ";
        current = current->nextNode;
    } while (current != NULL);
    cout << endl;
}

Node *LinkedList::_newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->nextNode = NULL;
    return temp;
}

void LinkedList::clear()
{
    //Check for empty list
    if (isEmpty())
    {
        return;
    }
    Node *current = head;
    //Delete each element iteratively
    while (current != NULL)
    {
        Node *temp = current;
        current = current->nextNode;
        delete temp;
    }
    head = NULL;
}
//Count the nodes in list recursively
int LinkedList::_recursiveCount(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return 1 + _recursiveCount(node->nextNode);
}

//Calculate size of list iteratively
int LinkedList::size()
{
    Node *current = head;
    int counter = 0;
    while (current != NULL)
    {
        current = current->nextNode;
        counter++;
    }
    return counter;
}

int LinkedList::count()
{
    return _recursiveCount(head);
}