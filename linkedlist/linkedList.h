#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>            
#include <stdlib.h>   

/*
Linked list class for node childen and siblings
*/

//node for linked list
typedef struct LinkedNode {
	void *data;
	struct Node *next;
	struct Node* prev;
} LinkedNode;

typedef struct List{
	LinkedNode* head;
	LinkedNode* tail;
	int size;
}List;

//inserts at the end of the linked list
extern int insertTail(List *list, void* data);

//removes specfic node
extern int removeNode(List *list, LinkedNode* node);

//prints data in order
extern void printList(List *list);

//allocates on node on heap
extern LinkedNode* createNode(void* data);

#endif

