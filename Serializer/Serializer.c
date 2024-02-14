#include "Serializer.h";

void saveTree(TreeNode *node, FILE *file)
{
    if (node != NULL)
    {
        if (node->parent == NULL)
        {
            fprintf(file, "/\n");
        }
        else
        {
            fprintf(file, "/%s\n", node->name);
        }
        LinkedNode * child = node->children->head;
        while (child != NULL)
        {
            saveTree(child,file);
            child = child->next;
        }
    }
}