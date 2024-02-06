#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/*
Linked list class for node childen and siblings
*/
//node for linked list
typedef struct Node {
	char  name[64];       
	char  type;
	struct node *next;
    struct node *prev;

} Node;

typedef struct List{
	Node* head;
	Node* parent;
	int size;
}List;

#endif // LINKED_LIST_H

