#include "Console.h"
int getInput(TreeNode *cwd, char *command, char *path, char *name)
{
    char input[100];
    pwd(cwd);
    printf("$");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    char temp[100];
    strcpy(temp, input);
    char *token = strtok(temp, " ");
    if (token == NULL)
    {
        return 0;
    }
    if(strcmp(token,"quit") == 0) {
        return -1;
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


int findCommand(TreeNode *cwd, char *command, char *path, char *name)
{
    if (strcmp(command, "mkdir") == 0)
    {
        if (name == NULL && path == NULL)
        {
            printf("'mkdir' missing operand\n");
            return 0;
        }
        else if (name == NULL)
        {
            return mkdir(cwd, path, NULL);
        }
        return mkdir(cwd, name, path);
    }
    else if (strcmp(command, "rmdir") == 0)
    {
        if (name != NULL)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        return rmdir(cwd, path);
    }
    else if (strcmp(command, "creat") == 0)
    {
        if (name == NULL && path == NULL)
        {
            printf("'creat' missing operand\n");
            return 0;
        }
        else if (name == NULL)
        {
            return creat(cwd, path, NULL);
        }
        return creat(cwd, name, path);
    }
    else if (strcmp(command, "rm") == 0)
    {
        if (name != NULL)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        return rm(cwd, path);
    }
    else if (strcmp(command, "cd") == 0)
    {
        if (name != NULL)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        cwd = cd(cwd, path);
        return 1;
    }
    else if (strcmp(command, "ls") == 0)
    {
        if (name != NULL)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        ls(cwd, path);
        return 1;
    }
    else if (strcmp(command, "pwd") == 0)
    {
        if (path != NULL)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        pwd(cwd);
        return 1;
    }
    else
    {
        printf("Unknown command: %s\n", command);
        return 0;
    }
}
