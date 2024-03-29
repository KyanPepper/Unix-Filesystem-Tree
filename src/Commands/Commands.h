#ifndef COMMANDS_H
#define COMMANDS_H
#include "../Tree/Tree.h"

// inserts new directory into tree
extern int mkdir(TreeNode *node, char name[64], char *pathname);

// removes directory if empty
extern int rmdir(TreeNode *node, char *pathname);

// inserts a new file inside tree
extern int creat(TreeNode *node, char name[64], char *pathname);

// removes file from tree
extern int rm(TreeNode *node, char *pathname);

// enters into new directory
extern TreeNode *cd(TreeNode *node, char *path);

// prints the working directory
extern void pwd(TreeNode *node);

// Lists all file in directory
extern void ls(TreeNode *node, char *path);

#endif
