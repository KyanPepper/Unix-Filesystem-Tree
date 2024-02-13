#include "Commands.h"
#include "string.h"

int mkdir(TreeNode *node, char name[64], char *pathname)
{
    TreeNode *current = node;
    TreeNode *parent;
    char *token = strtok(pathname, "/");
    char *nextToken = NULL;
    char string[64];
    while (token != NULL)
    {
        nextToken = strtok(NULL, "/");
        strcpy(string, token);
        TreeNode *child = matchTreeNode(current->children, string);
        if ((child == NULL) && (nextToken != NULL))
        {
            printf("Error: Directory %s does not exist\n", token);
            return 0;
        }
        parent = current;
        current = child;
        token = nextToken;
    }
    insertTreeNode(parent, name, 'd');
    return 1;
}


int rmdir(TreeNode *node, char *pathname)
{
    TreeNode *current = node;
    TreeNode *parent;
    LinkedNode* parentOfChild;
    char *token = strtok(pathname, "/");
    char *nextToken = NULL;
    char string[64];
    TreeNode *child;
    while (token != NULL)
    {
        nextToken = strtok(NULL, "/");
        strcpy(string, token);
        child = matchTreeNode(current->children, string);
        parentOfChild = matchListNode(current->children,string);
        if ((child == NULL) && (nextToken != NULL))
        {
            printf("Error: Directory %s does not exist\n", token);
            return 0;
        }
        parent = current;
        current = child;
        token = nextToken;
    }
    if((child->children->head != NULL)){
        printf("Error: Directory %s is not empty\n", token);
        return 0;
    }
        free(child);
        removeNode(parent->children,parentOfChild);
        return 1;
}


int creat(TreeNode* node, char name[64], char* pathname){
    TreeNode *current = node;
    TreeNode *parent;
    char *token = strtok(pathname, "/");
    char *nextToken = NULL;
    char string[64];
    while (token != NULL)
    {
        nextToken = strtok(NULL, "/");
        strcpy(string, token);
        TreeNode *child = matchTreeNode(current->children, string);
        if ((child == NULL) && (nextToken != NULL))
        {
            printf("Error: Directory %s does not exist\n", token);
            return 0;
        }
        parent = current;
        current = child;
        token = nextToken;
    }
    insertTreeNode(parent, name, 'f');
    return 1;
}

int rm(TreeNode* node, char*pathname){
    TreeNode *current = node;
    TreeNode *parent;
    LinkedNode* parentOfChild;
    char *token = strtok(pathname, "/");
    char *nextToken = NULL;
    char string[64];
    TreeNode *child;
    while (token != NULL)
    {
        nextToken = strtok(NULL, "/");
        strcpy(string, token);
        child = matchTreeNode(current->children, string);
        parentOfChild = matchListNode(current->children,string);
        if ((child == NULL) && (nextToken != NULL))
        {
            printf("Error: Directory %s does not exist\n", token);
            return 0;
        }
        parent = current;
        current = child;
        token = nextToken;
    }
        free(child);
        removeNode(parent->children,parentOfChild);
        return 1;
}

TreeNode* cd(TreeNode* node, char* path){
    TreeNode* pCur = node;
    if(path == NULL){
        while(strcmp(pCur->name, "/") != 0) {
            pCur = pCur->parent;
        }
    }
    char *token = strtok(path, "/");
    char *nextToken = NULL;
    char string[64];
    TreeNode *child;
    while (token != NULL)
    {
        nextToken = strtok(NULL, "/");
        strcpy(string, token);
        child = matchTreeNode(pCur->children, string);
        if ((child == NULL) && (nextToken != NULL))
        {
            printf("Error: Directory %s does not exist\n", token);
            return NULL;
        }
        pCur = child;
        token = nextToken;
    }
    return child;
}

void ls(TreeNode* node, char *path){
    if(path == NULL){
        printList(node->children);
        return;
    }
    TreeNode* pcur = cd(node,path);
    if(pcur == NULL){
        printf("Error: Directory Path Doesnt Exit");
        return;
    }
    printList(pcur);
}


