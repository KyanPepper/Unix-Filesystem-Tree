#include "../Commands/Commands.h"
// searializes tree by preorder traversal
extern void saveTree(TreeNode *node);

// helper function for saveTree
extern void saveTreeHelper(TreeNode *node, FILE *file, char *path);

// deserializes tree
extern Tree loadTree();
