#include <stdio.h>            
#include <stdlib.h>            
#include "Tests/Test.h"

#include "Console/Console.h"
int main() {
	runTests();
	Tree tree;
	initTree(&tree);
	TreeNode* cwd = tree.root;
	int i,j;
	while (1)
	{
		char command[64], path[64], name[64];

		 i = getInput(cwd, command, path, name);
		if(i == 1){
			 j = findCommand(cwd, command, path, name);
		}
		if(j == -1){
			break;
		}
		

	}
	printf("Quitting...");
}

