#include "Tree.h"
#include <string.h>

TreeNode* createTreeNode(char name[64], char type, TreeNode* parent){
    TreeNode *node = malloc(sizeof(TreeNode));
    strcpy(node->name, name); 
    node->type = type;
    if(type == 'f'){
        node->children = NULL;
    }else{
        node->children = malloc(sizeof(List));
    }
    node->parent = parent;
    return node;
}


void initTree(Tree* tree){
    TreeNode* root = createTreeNode("/", 'd', NULL);
    tree->root = root;
    tree->size = 0;
}

int insertTreeNode(Tree* tree, char name[64], char type){
   
    
}
