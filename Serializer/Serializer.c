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
    }

    fclose(file);
}