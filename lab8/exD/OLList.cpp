// OLList.cpp
// ENSF 337  Lab 8 Exercise C and D

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        // point three
        if(itemA == maybe_doomed->item)
        {
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
    }
}

void OLList::destroy()
{
    Node *current = headM;
    while(headM != 0)
    {
        headM = headM->next;
        delete current;
        current = headM;
    }
    headM = 0;
}

void OLList::copy(const OLList& source)
{
    Node *currentdest, *currentsource;
    Node *newnode = new Node;

    headM = newnode;
    currentdest = newnode; //keeps track of dest
    currentsource = source.headM->next; //keeps track of source

    newnode->item = source.headM->item;

    while(currentsource != 0)
    {
        Node *temp = new Node;
        currentdest->next = temp; //points previous next to new node
        temp->item = currentsource->item; //copies item from source to dest
        
        currentdest = temp; //moves pointer to next node 
        currentsource = currentsource->next; //moves pointer to next node
    }
    currentdest->next = 0;
}


