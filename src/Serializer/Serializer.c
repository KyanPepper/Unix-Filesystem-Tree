#include "Serializer.h";

void saveTree(TreeNode *node, FILE *file, char *parents)
{
    if (node != NULL)
    {
        char *new_parents;
        asprintf(&new_parents, "%s/%s", parents, node->name);
        if (node->parent == NULL)
        {
            fprintf(file, "d /\n");
        }
        else
        {
            fprintf(file, "%c %s/%s\n", node->type, new_parents, node->name);
        }
        LinkedNode *child = node->children->head;
        while (child != NULL)
        {
            saveTree(child, file, parents);
            child = child->next;
        }
        free(new_parents);
    }
}

void loadTree(TreeNode *node, FILE *file)
{

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
         while (fgets(line, sizeof(line), file) != NULL)
    {
        char type;
        char name[50];
        char path[100]; 
        sscanf(line, "%c %s\n", &type, path);
        char *token;
        char *last_part = NULL;
        char *in_between = NULL;
        token = strtok(path, "/");
        while (token != NULL) {
            in_between = last_part;
            last_part = token; 
            token = strtok(NULL, "/");
        }
        strcpy(name, last_part);
        if (in_between != NULL) {
            strcat(in_between, "/");
            strcat(in_between, name);
            strcpy(name, in_between);
        }
        if(type == 'd'){
            mkdir(node,name,path);
        }else{
            creat(node,name,path);
        }
        
    }
    fclose(file);
    }
}