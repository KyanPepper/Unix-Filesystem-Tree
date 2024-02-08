#include "Test.h"
#include "../LinkedList/LinkedList.h"
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

void runTests()
{
    if (testInsert() == 1)
    {
        printf("Linked List Insert Passed Insert Passed");
    }
    printf("\nPrint List Test, Expect 1....7 \n");
    testPrintList();
    printf("\nRemove Node Expected 2 \n New List:");
    removeNodeTest();
}

