#include "string.h"
#include <stdio.h>
// returns 1 if input is vaild return 0 if not
int getInput(char *cwd, char *command, char *path, char *name)
{
    char input[100];
    printf("%s$ ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    char temp[100];
    strcpy(temp, input);
    char *token = strtok(temp, " ");
    if (token == NULL)
    {
        return 0;
    }
    strcpy(command, token);

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        name = NULL;
        path = NULL;
        return 1;
    }
    strcpy(path, token);

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        name = NULL;
        return 1;
    }
    strcpy(name, token);

    token = strtok(NULL, " ");
    if (token != NULL)
    {
        printf("Command '%s' not found.\n", temp);
        return 0;
    }
    return 1;
}