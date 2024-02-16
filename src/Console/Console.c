#include "Console.h"
int getInput(TreeNode *cwd, char *command, char *path, char *name)
{
    char input[100];
    pwd(cwd);
    printf("$");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    char temp[100] ="";
    char temp2[100] ="";
    char temp3[100] = "";
    char *token = NULL;
    token = strtok(input, " ");
    if (token == NULL)
    {
        return 0;
    }
    strcpy(temp, token);
    strcpy(command, temp);

    token = strtok(NULL, " ");
   
    if (token == NULL)
    {
        name = NULL;
        path = NULL;
        return 1;
    }
    strcpy(temp2, token);
    strcpy(path, temp2);

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        name = NULL;
        return 1;
    }
    strcpy(temp3, token);
    strcpy(name, temp3);

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
    if (strcmp(command, "quit") == 0){
        return -1;
    }
    if (strcmp(command, "mkdir") == 0)
    {
        if ((strlen(name) == 0) && (strlen(path) == 0))
        {
            printf("'mkdir' missing operand\n");
            return 0;
        }
        else if (strlen(name) == 0)
        {
            return mkdir(cwd, path, NULL);
        }
        return mkdir(cwd, name, path);
    }
    else if (strcmp(command, "rmdir") == 0)
    {
        if (strlen(name) != 0)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        return rmdir(cwd, path);
    }
    else if (strcmp(command, "creat") == 0)
    {
        if ((strlen(name) == 0) && (strlen(path) == 0))
        {
            printf("'creat' missing operand\n");
            return 0;
        }
        else if (strlen(name) == 0)
        {
            return creat(cwd, path, NULL);
        }
        return creat(cwd, name, path);
    }
    else if (strcmp(command, "rm") == 0)
    {
        if (strlen(name) != 0)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        return rm(cwd, path);
    }
    else if (strcmp(command, "cd") == 0)
    {
        if (strlen(name) != 0)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        return -7;
    }
    else if (strcmp(command, "ls") == 0)
    {
        if (strlen(name) != 0)
        {
            printf("'unknown operand %s'", name);
            return 0;
        }
        ls(cwd, path);
        return 1;
    }
    else if (strcmp(command, "pwd") == 0)
    {
        if (strlen(path) != 0)
        {
            printf("'unknown operand %s'", path);
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
