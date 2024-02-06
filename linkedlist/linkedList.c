#include "linkedList.h"

LinkedNode* createNode(void* data){
   LinkedNode *node = malloc (sizeof(data));
   return node;
}


int insertTail(List *list, void* data){
    LinkedNode *node = createNode(data);
    if(node != NULL){
        //intialize head
        if(list->head == NULL){
            list->head = node;
            return 1;
        }
        //intialize tail
        if(list->tail == NULL){
            list->tail = node;
            list->head->next = list->tail;
            list->tail->prev = list->head;
            return 1;
        }
        //add to end of list
        LinkedNode* pCur = list->tail; 
        list->tail = node;
        list->tail->prev = pCur;
        pCur->next = list->tail;
        return 1;
    }
    return 0;
}