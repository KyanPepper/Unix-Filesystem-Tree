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

//create node based on weather its a file or directory and adds to link list
extern TreeNode* createTreeNode(char name[], char type, TreeNode* parent);

//inits null value for root and 0 for size
extern void initTree(Tree* tree);

//Traverses list and returns node with matching data
extern TreeNode* matchTreeNode(List* list, char *c);

//traves list and return listnode with matching data
extern LinkedNode* matchListNode(List *list, char string[64]);

//Does setup for insertTreeNode
extern int InsertTreeNodeUser(Tree* tree, char name[64], char type);


//Recursivly inserts into tree based on node path MUST CHECK HAVE INPUT FORMATED BEFOREHAND
//Return results: 0: Path taken.... 1:Insert Worked 
extern int insertTreeNode(TreeNode* node, char name[64], char type);

//prints value for tree
extern void printTree();
