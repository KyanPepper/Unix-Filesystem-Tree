#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/*
Linked list class for node childen and siblings
*/
//node for linked list
typedef struct Node {
	char  name[64];       
	char  type;
	struct Node *next;
    struct Node *prev;

} Node;
typedef struct List{
	Node* head;
	Node* tail;
	int size;
}List;


extern int insert(List &list, Node* node);

extern int removeNode(List &list, Node* node);

extern void printList(List &list);



#endif // LINKED_LIST_H

