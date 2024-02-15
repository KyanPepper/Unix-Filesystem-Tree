#include "Test.h"
#include "string.h"
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
    char patha[] = "/";
    char pathb[] = "/";
    char dpatha[] = "/a";
    char dpathb[] = "/b";
    TreeNode *root = tree.root;
    mkdir(root, "a", patha);
    mkdir(root, "b", pathb);
    if (root->children != NULL && root->children->size == 2)
    {
        List *childList = root->children;
        printf("Mkdir test passed\n");
        rmdir(root, dpatha);
        rmdir(root, dpathb);
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
    mkdir(root, "a", NULL);
    mkdir(root, "b", NULL);
    mkdir(root, "c", NULL);
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

void testCreat()
{
    Tree tree;
    initTree(&tree);
    char path[] = "/";
    char patha[] = "a";
    char pathb[] = "/b";
    char pathc[] = "/c";
    char pathy[] = "/y";
    TreeNode *root = tree.root;
    mkdir(root, "a", path);
    mkdir(root, "b", path);
    mkdir(root, "c", path);
    creat(root, "y", path);
    TreeNode *file = (TreeNode *)root->children->tail->data;
    if ((file->type == 'f') && (file->children == NULL))
    {
        printf("Creat test passed");
        free(file);
        rmdir(root, patha);
        rmdir(root, pathb);
        rmdir(root, pathc);
        free(root->children);
        free(root);
        return;
    }
    printf("Creat test failed");
    return;
}

void testRm(){

    Tree tree;
    initTree(&tree);
    char path[] = "/";
    char pathb[] = "/a";
    char pathb2[] = "/a/b";
    char pathy[] = "/y";
    TreeNode *root = tree.root;
    mkdir(root, "a", path);
    creat(root,"b",path);
    creat(root, "y", path);
    rm(root,pathb2);
    rm(root,pathy);
    
    if(root->children->size == 2){
        printf("\nRm test passed\n");
        rmdir(root,pathb);
        free(root->children);
        free(root);
        return;
    }
    printf("rm test failed");
    return;
}

void testCd(){
    Tree tree;
    initTree(&tree);
    TreeNode *root = tree.root;
    char patha[] = "/";
    char pathb[] = "/a";
    char pathb2[] = "/a/b";
    mkdir(root, "a", patha);
    creat(root,"b",pathb);
    TreeNode* pCur = cd(root,pathb2);
    if(strcmp(pCur->name,"b") == 0){
        printf("CD test passed\n");
        TreeNode* pParent = pCur->parent;
        char pathc[] = "/a/b";
        rm(root,pathc);
        rmdir(root,"/a");
        free(root->children);
        free(root);
        return;
    }
    printf("CD test failed");
    return;
}

void testLs(){
    Tree tree;
    initTree(&tree);
    char path[] = "/";
    char patha[] = "/a";
    char pathb[] = "/b";
    char pathc[] = "/c";
    TreeNode *root = tree.root;
    printf("ls test expected: a b c actual: ");
    mkdir(root, "a", path);
    mkdir(root, "b", path);
    mkdir(root, "c", path);
    ls(root,NULL);
    rmdir(root, patha);
    rmdir(root, pathb);
    rmdir(root, pathc);
    free(root->children);
    free(root);
    printf(" ls test passed");

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
    testCreat();
    //leak on create
    testRm();
    testCd();
    testLs();
    printf("\n");
}

