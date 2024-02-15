#include "../Commands/Commands.h"

//returns 1 if input is vaild return 0 if not
extern int getInput(char* cwd, char *command, char *path, char *name);

//if else chain for all commands
extern int findCommand(TreeNode* cwd, char *command, char *path, char *name);


