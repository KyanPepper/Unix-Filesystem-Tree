#include "../LinkedList/LinkedList.h"


//Tree node contains data and List of children aswell as parent
typedef struct TreeNode {
    char  name[64];       
	char  type;
    List *children; 
    struct TreeNode *parent;
} TreeNode;

typedef struct Tree{
    TreeNode* root;
    int size;
} Tree;

//create node based on weather its a file or directory
extern TreeNode* createTreeNode(char name[], char type, TreeNode* parent);

//inits null value for root and 0 for size
extern void initTree(Tree* tree);

//inserts into tree based on node postition 
extern int insertTreeNode(Tree* tree, char name[64], char type);

//prints value for tree
extern void printTree();
