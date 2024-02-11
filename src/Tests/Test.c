#include "Test.h"
#include "../Commands/Commands.h"
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
    for (int i = 1; i <= 7; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        insertTail(&list, data);
    }
    printList(&list);
    printf("\n Print List Passed");
}

int removeNodeTest()
{
    List list;
    initList(&list);
    for (int i = 1; i <= 7; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        insertTail(&list, data);
    }
    LinkedNode *pcur = list.head;
    pcur = pcur->next;
    removeNode(&list, pcur);

    printList(&list);
    printf("\n Remove Node Passed");

    return 1;
}

void testMkdir()
{
    Tree tree;
    initTree(&tree);
    char patha[] = "/a";
    char pathb[] = "/b";
    char pathc[] = "/c";
    TreeNode *root = tree.root;
    mkdir(root, "a", patha);
    mkdir(root, "b", pathb);
    mkdir(root, "c", pathc);
    if (root->children != NULL)
    {
        List *childList = root->children;
        printf("Mkdir test passed\n");
        rmdir(root, patha);
        rmdir(root, pathb);
        rmdir(root, pathc);
        free(root->children);
        free(root);
        return;
    }
    printf("mkdir test failed\n");
    return;
}

void testRmdir()
{
    Tree tree;
    initTree(&tree);
    char patha[] = "/a";
    char pathb[] = "/b";
    char pathc[] = "/c";
    TreeNode *root = tree.root;
    mkdir(root, "a", patha);
    mkdir(root, "b", pathb);
    mkdir(root, "c", pathc);
    rmdir(root, patha);
    rmdir(root, pathb);
    rmdir(root, pathc);
    List *childList = root->children;
    if (childList->size == 0)
    {
        printf("rmdir tests passed\n");
        free(root->children);
        free(root);
        return;
    }

    printf("rmkdir test failed\n");
    return;
}

void runTests()
{
    /*   if (testInsert() == 1)
       {
           printf("Linked List Insert Passed Insert Passed");
       }
       printf("\nPrint List Test, Expect 1....7 \n");
       testPrintList();
       printf("\nRemove Node Expected 2 \n New List:");
       removeNodeTest(); */
    testMkdir();
    testRmdir();
    

}
