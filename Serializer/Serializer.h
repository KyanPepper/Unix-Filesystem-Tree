#include "../Tree/Tree.h"

//searializes tree by preorder traversal
extern void saveTree(TreeNode* node,FILE* file, char *parents);

//desearializes tree
extern void loadTree(TreeNode* node, FILE file);

