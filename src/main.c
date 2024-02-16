
#include "Console/Console.h"
int main()
{
	// runTests();
	Tree tree;
	initTree(&tree);
	TreeNode *cwd = tree.root;
	int i, j;
	while (1)
	{
		char command[64]= "";
		char path[64] = "";
		char name[64] = "";

		i = getInput(cwd, command, path, name);
		if (i == 1)
		{
			j = findCommand(cwd, command, path, name);
		}
		if (j == -1)
		{
			break;
		}
		else if (j == -7)
		{
			TreeNode *newCWD = cd(cwd, path);
			if (newCWD != NULL)
			{
				cwd = newCWD;
			}
		}
	}
	printf("Quitting...");
}
