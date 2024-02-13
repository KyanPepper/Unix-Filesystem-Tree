#include "Tree.h"
#include <string.h>
#include <ctype.h>

TreeNode *createTreeNode(char name[64], char type, TreeNode *parent)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    strcpy(node->name, name);
    node->type = type;
    node->parent = parent;
    if (type == 'f')
    {
        node->children = NULL;
    }
    else
    {
        node->children = malloc(sizeof(List));
        initList(node->children);
    }
    if (strcmp(name, "/") == 0)
    {
        return node;
    }
    else
    {
        insertTail(parent->children, node);
    }
    return node;
}

void initTree(Tree *tree)
{
    TreeNode *root = createTreeNode("/", 'd', root);
    tree->root = root;
    tree->size = 0;
}

TreeNode *matchTreeNode(List *list, char string[64])
{
    if(list == NULL){
        return NULL;
    }
    LinkedNode *pcur = list->head;
    while (pcur != NULL)
    {
        TreeNode *pdata = (TreeNode *)pcur->data;
        if (strcmp(pdata->name, string) == 0)
        {
            return pdata;
        }
        pcur = pcur->next;
    }
    return NULL;
}

LinkedNode *matchListNode(List *list, char string[64])
{
    if(list == NULL){
        return NULL;
    }
    LinkedNode *pcur = list->head;
    while (pcur != NULL)
    {
        TreeNode *pdata = (TreeNode *)pcur->data;
        if (strcmp(pdata->name, string) == 0)
        {
            return pcur;
        }
        pcur = pcur->next;
    }
    return NULL;
}


int InsertTreeNodeUser(Tree *tree, char name[64], char type)
{
    int index = -1;
    return insertTreeNode(tree->root, name, type);
}

int insertTreeNode(TreeNode *node, char name[64], char type)
{
        createTreeNode(name, type, node);
        return 1;
}
