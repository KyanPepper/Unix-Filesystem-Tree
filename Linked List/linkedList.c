#include "linkedList.h"

int initList(List *list)
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}
LinkedNode *createNode(void *data)
{
    LinkedNode *node = malloc(sizeof(LinkedNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int insertTail(List *list, void *data)
{
    LinkedNode *node = createNode(data);
    if (node != NULL)
    {
        // intialize head
        if (list->head == NULL || list->size == 0)
        {
            list->head = node;
            list->size += 1;
            return 1;
        }
        // intialize tail
        if (list->tail == NULL)
        {
            list->tail = node;
            list->head->next = list->tail;
            list->tail->prev = list->head;
            list->size += 1;
            return 1;
        }
        // add to end of list
        LinkedNode *pCur = list->tail;
        list->tail = node;
        list->tail->prev = pCur;
        pCur->next = list->tail;
        list->size += 1;
        return 1;
    }
    return 0;
}

void printList(List *list)
{
    LinkedNode *pcur = list->head;
    while (pcur != NULL)
    {
        printf("%d ", *(int*)pcur->data);
        pcur = pcur->next;
    }
}

int removeNode(List *list, LinkedNode *node)
{
    if (node != NULL)
    {
        // remove if head
        if (node == list->head)
        {
            list->head = node->next;
            free(node);
            list->size -= 1;
            return 1;
        }
        // remove if tail
        if (node == list->tail)
        {
            list->tail = node->prev;
            free(node);
            list->size -= 1;
            return 1;
        }
        // remove if between head and tail
        LinkedNode *pcur = node->prev;
        pcur->next = node->next;
        node->prev = pcur;
        free(node);
        list->size -= 1;
        return 1;
    }

    return 0;
}

int testInsert()
{
    List list;
    initList(&list);
    for (int i = 1; i <= 7; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        insertTail(&list, data);
    }
    if (list.size == 7)
    {
        LinkedNode *pcur = list.head;
        for (int i = 1; i <= 7; i++)
        {
            if (pcur != NULL && *(int *)pcur->data != i)
            {
                printf("Value error: %d\n", *(int *)pcur->data);
                return 0;
            }
            pcur = pcur->next;
        }
        return 1;
    }
    printf("size error");
    return 0;
}

void testPrintList()
{
    List list;
    initList(&list);
    for(int i = 1; i<=7; i++){
        int *data = malloc(sizeof(int));
        *data = i;
        insertTail(&list, data);
    }
    printList(&list);
    printf("\n Print List Passed");
}

int removeNodeTest(){
    List list;
    initList(&list);
    for(int i = 1; i<=7; i++){
        int *data = malloc(sizeof(int));
        *data = i;
        insertTail(&list, data);
    }
    LinkedNode* pcur = list.head;
    pcur = pcur->next;
    removeNode(&list,pcur);
    
    printList(&list);
    printf("\n Remove Node Passed");

    return 1;
}

int main()
{
    if (testInsert() == 1)
    {
        printf("Insert Passed");
    }
    printf("\nPrint List Test, Expect 1....7 \n");
    testPrintList();
    printf("\nRemove Node Expected 2 \n New List:");
    removeNodeTest();
}