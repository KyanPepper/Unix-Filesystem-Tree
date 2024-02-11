#include "Tree.h"
#include <string.h>
#include <ctype.h>

TreeNode *createTreeNode(char name[64], char type, TreeNode *parent)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    strcpy(node->name, name);
    node->type = type;
    if (type == 'f')
    {
        node->children = NULL;
    }
    else
    {
        node->children = malloc(sizeof(List));
    }
    node->parent = parent;
    insertTail(parent->children, node);
    return node;
}

void initTree(Tree *tree)
{
    TreeNode *root = createTreeNode("/", 'd', NULL);
    tree->root = root;
    tree->size = 0;
}

TreeNode *matchTreeNode(List *list, char c, int *index)
{
    LinkedNode *pcur = list->head;
    while (pcur != NULL)
    {
        TreeNode *pdata = (TreeNode *)pcur->data;
        if (pdata->name[*index] == c)
        {
            return pdata;
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
  if(node->children != NULL){
    createTreeNode(name,type ,node);
    return 1;
  }

    return 0;
}


