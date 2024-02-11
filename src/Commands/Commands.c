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
