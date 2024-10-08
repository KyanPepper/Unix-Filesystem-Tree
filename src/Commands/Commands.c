#include "Commands.h"

int mkdir(TreeNode *node, char name[64], char *pathname)
{
    if ((pathname == NULL) || strcmp(pathname, "/") == 0)
    {
        // None matching node in list
        if (matchTreeNode(node->children, name) == NULL)
        {
            insertTreeNode(node, name, 'd');
            return 1;
        }
        // Matching node in list
        else
        {
            printf("Directory %s already exists\n", name);
            return 0;
        }
    }
    TreeNode *pCur = cd(node, pathname);
    if (pCur == NULL)
    {
        return 0;
    }
    insertTreeNode(pCur, name, 'd');
    return 1;
}

int rmdir(TreeNode *node, char *pathname)
{
    if (pathname == NULL)
    {
        printf("No Directory Specified");
        return 0;
    }

    TreeNode *pCur = cd(node, pathname);
    if (pCur == NULL)
    {
        return 0;
    }
    TreeNode *parent = pCur->parent;
    LinkedNode *listParentNode = matchListNodeData(parent->children, pCur);
    if (pCur->children->size > 0)
    {
        printf("Directory %s is not empty\n", pCur->name);
        return 0;
    }
    free(pCur);
    removeNode(parent->children, listParentNode);
    return 1;
}

int creat(TreeNode *node, char name[64], char *pathname)
{
    if ((pathname == NULL) || strcmp(pathname, "/") == 0)
    {
        insertTreeNode(node, name, 'f');
        return 1;
    }
    TreeNode *pCur = cd(node, pathname);
    if (pCur == NULL)
    {
        return 0;
    }
    insertTreeNode(pCur, name, 'f');
    return 1;
}

int rm(TreeNode *node, char *pathname)
{
    if (pathname == NULL)
    {
        printf("No Directory Specified");
        return 0;
    }

    TreeNode *pCur = cd(node, pathname);
    if (pCur == NULL || pCur->type == 'd')
    {
        printf("rm cannot remove directory\n");
        return 0;
    }
    TreeNode *parent = pCur->parent;
    LinkedNode *listParentNode = matchListNodeData(parent->children, pCur);
    free(pCur);
    removeNode(parent->children, listParentNode);
    return 1;
}

TreeNode *cd(TreeNode *node, char *path)
{
    TreeNode *pCur = node;
    if (path == NULL)
    {
        while (strcmp(pCur->name, "/") != 0)
        {
            pCur = pCur->parent;
            return pCur;
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
            printf("Error: Directory %s does not exist\n", path);
            return NULL;
        }
        pCur = child;
        token = nextToken;
    }
    if (child == NULL)
    {
        printf("Error: Directory %s does not exist\n", path);
        return NULL;
    }
    return child;
}

void ls(TreeNode *node, char *path)
{
    if (path == NULL)
    {
        printList(node->children);
        printf("\n");
        return;
    }
    TreeNode *pcur = cd(node, path);
    if (pcur == NULL)
    {
        printf("Error: Directory Path doesn't Exit");
        printf("\n");
        return;
    }
    printList(pcur->children);
    printf("\n");
}

void pwd(TreeNode *node)
{
    TreeNode *pCur = node->parent;
    if (pCur != NULL)
    {
        pwd(pCur);
    }
    if (strcmp(node->name, "/") == 0)
    {
        printf("/");
    }
    else
    {
        printf("%s/", node->name);
    }
}
