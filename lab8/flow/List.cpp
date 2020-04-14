#include <iostream>
#include <stdlib.h>
using namespace std;
#include "List.h"
#include "hydro.h"

FlowList::FlowList()
{
	head = 0;
	body = 0;
}

void FlowList::setnode(int a,double b)
{
	if(head==0)
	{
		body = new Node;
		head = body;
		body->item.year = a;
		body->item.flow = b;
	}
	else
	{
		body->next = new Node;
		body=body->next;
		body->item.year = a;
		body->item.flow = b;
	}
	body->next=0;	
}

void FlowList::sort_nodes()
{
	double temp;
	body = head;

	if(head == 0)
		return;
	
	else
	{
		while(body != 0)
		{
			index = body->next;

			while(index != NULL)
			{
				if(body->item.flow > index->item.flow)
				{
					temp = body->item.flow;
					body->item.flow = index->item.flow;
					index->item.flow = temp;
				}
				index = index->next;
			}
			body = body->next;
		}
	}
}

void FlowList::reset_flow()
{
	body = head;
}

double FlowList::get_flow() const
{
  return body->item.flow;
}

int FlowList::get_year() const
{
  return body->item.year;
}

void FlowList::next_flow() 
{
 	body=body->next;
}

void FlowList::destroy()
{
	if(body==head)
	{
 	head=head->next;
 	delete body;
	}
	else
	{
		index = head;
		while(index->next!=body) index=index->next;
		index->next=body->next;
		delete body;
	}
}

void FlowList::insert(int year,double flow)
{
body = head;
if(head->item.flow>flow)
{
 body = new Node;
      body->item.year = year;
 body->item.flow = flow;
 body->next = head;
 head = body;
}
    else
{
while(body->next->next != 0 && body->next->item.flow<flow) next_flow();

Node * after = body->next;

 body->next = new Node;
 body=body->next;
              body->item.year = year;
         body->item.flow = flow;
 body->next=after;
}
}



