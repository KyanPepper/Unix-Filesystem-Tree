#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>            
#include <stdlib.h>   

//node for linked list (void* data is generic thus can use treenode make sure to cast)
typedef struct LinkedNode {
	void *data;
	struct LinkedNode *next;
	struct LinkedNode *prev;
} LinkedNode;

//Linked list with a few operations
typedef struct List{
	LinkedNode* head;
	LinkedNode* tail;
	int size;
}List;

//constructer for List
extern int initList(List *list);

//inserts at the end of the linked list
extern int insertTail(List *list, void* data);

//removes specfic node
extern int removeNode(List *list, LinkedNode* node);

//prints data in order
extern void printList(List *list);

//allocates on node on heap
extern LinkedNode* createNode(void* data);



#endif

