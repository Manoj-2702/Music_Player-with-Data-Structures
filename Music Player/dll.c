#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t *temp=(node_t*)malloc(sizeof(node_t));
	temp->data=data;
	temp->prev=NULL;
    temp->next=NULL;
    if(list->head==NULL)
    {
        list->head=list->tail=temp;
    }
    else
    {
        temp->next=list->head;
        temp->next->prev=temp;
        list->head=temp;
    }
	list->size += 1;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t* temp=(node_t*)malloc(sizeof(node_t));
	temp->data=data;
	temp->prev=NULL;
    temp->next=NULL;
    if(list->head==NULL)
    {
        list->head=list->tail=temp;
    }
    else
    {
    	temp->prev=list->tail;
        temp->prev->next=temp;
        list->tail=temp;
    }
	list->size += 1;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
    node_t *temp=list->head;
    if(temp == NULL)
    {
        return;
    }
    else
    {
        while((temp != NULL) && (temp->data != prev))
        {
            temp=temp->next;
        }
        if(temp == NULL)
        {
           return;
        }
        else if(temp->data == prev)
        {
            node_t *p=(node_t*)malloc(sizeof(node_t));
            p->data=data;
            p->next=temp->next;
            p->prev=temp;
			if(temp->next!=NULL)
            	temp->next->prev=p;
            temp->next=p;
			list->size += 1;
        }
    }
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	if(list->head==NULL)
    {
        return;
    }
    else
    {
        node_t *temp;
        if(list->head ==list->tail)
        {
            list->tail=NULL;
        }
        temp=list->head;
        if(list->head->next==NULL)
            list->head =NULL;
        else
            list->head =list->head->next;
        free(temp);
        temp=NULL;
        if(list->head != NULL)
        {
            list->head->prev=NULL;
        }
        list->size -= 1;
    }
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	if (list->tail != NULL)
    {
        node_t *temp;
        if (list->head == list->tail)
            list->head = NULL;
        temp = list->tail;
        if (list->tail->prev != NULL)
        {
            list->tail = list->tail->prev;
        }
        else
        {
            list->tail = NULL;
        }
        free(temp);
        temp = NULL;
        if (list->tail != NULL)
            list->tail->next = NULL;
        list->size -= 1;
    }
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	if(list->head==NULL)
    {
        return;
    }
    else
    {
        node_t *p=list->head;
        while(p!=NULL && p->data != data)
        {
            p=p->next;
        }
        if(p != NULL)
        {
        	if(p == list->head)
                delete_front(list);
            else if(p == list->tail)
                delete_back(list);
            else
            {
                p->prev->next=p->next;
                p->next->prev=p->prev;
                free(p);
                p=NULL;
                list->size -=1;
            }
        }
    }
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
	node_t *p=list->head;
	while((p->data!=data) && (p != NULL))
	{
		p=p->next;
	}
	if(p==NULL)
		return NULL;
	else if(p->data == data)
	{
		return p;
	}
    else
    {
        return NULL;
    }
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

