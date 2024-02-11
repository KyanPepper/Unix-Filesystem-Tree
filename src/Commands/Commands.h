#ifndef COMMANDS_H
#define COMMANDS_H
#include "../Tree/Tree.h"

//inserts new directory into tree
extern int mkdir(TreeNode* node, char name[64],char* pathname);


//removes directory if empty
extern int rmdir(TreeNode* node,char* pathname);

//inserts a new file inside tree
extern int creat(TreeNode* node,char name[64], char* pathname);
#endif
