#include "Commands.h"
#include "string.h"

int mkdir(TreeNode* node, char name[64], char *pathname){
    TreeNode *current = node;
    TreeNode* parent;
    char* token = strtok(pathname, "/");
    char* nextToken = NULL;
    char string[64];
    while (token != NULL) {
        nextToken = strtok(NULL, "/");
        strcpy(string,token);
        TreeNode *child = matchTreeNode(current->children, string);
        if ((child == NULL) && (nextToken != NULL)) {
            printf("Error: Directory %s does not exist\n", token);
            return 0;
        }
        parent = current;
        current = child;
        token = nextToken;
    }
    insertTreeNode(parent,name,'d');
}