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
		char command[64] = "";
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
			TreeNode *newCWD;
			if (strlen(path) == 0)
			{
				newCWD = tree.root;
			}
			else if (strcmp(path, "..") == 0)
			{
				newCWD = cwd->parent;
			}
			else
			{
				newCWD = cd(cwd, path);
			}
			if (newCWD != NULL && newCWD->type != 'f')
			{
				cwd = newCWD;
			}
			else if (newCWD != NULL && newCWD->type == 'f')
			{
				printf("%s is not a directory!\n", newCWD->name);
			}
		}
		else if (j == -6)
		{
			FILE *file = fopen("treefile.txt", "w");
			saveTree(tree.root, file, "");
			fclose(file);
		}
		else if (j == -8)
		{
			FILE *file = fopen("treefile.txt", "r");
			loadTree(tree.root, file);
			fclose(file);
		}
	}
	printf("Quitting...\n");
	FILE *file = fopen("treefile.txt", "w");
	saveTree(tree.root, file, "");
	fclose(file);
}
