#include "Commands.h"


int mkdir(TreeNode* node, char name[64], char *pathname){
    TreeNode *current = node;
    TreeNode* parent;
    char* token = strtok(pathname, "/");
    while (token != NULL) {
        TreeNode *child = matchTreeNode(current->children, token);
        if ((child == NULL) || (child->type='f')) {
            printf("Error: Directory %s does not exist\n", token);
            return 0;
        }
        parent = current;
        current = child;
        token = strtok(NULL, "/");
    }
    insertTreeNode(parent,name,'d');
}