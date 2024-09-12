#include "Serializer.h"

void saveTree(TreeNode *node)
{
    FILE *file = fopen("treefile.txt", "w");
    saveTreeHelper(node, file, "");
    fclose(file);
}

void saveTreeHelper(TreeNode *node, FILE *file, char *path)
{
    if (node == NULL)
    {
        return;
    }

    fprintf(file, "%c %s%s\n", node->type, path, node->name);
    // is a directory
    if (node->type == 'd')
    {
        LinkedNode *pcur = node->children->head;
        while (pcur != NULL)
        {
            TreeNode *pdata = (TreeNode *)pcur->data;

            char newPath[64];
            strcpy(newPath, path);
            strcat(newPath, node->name);
            if (strcmp(newPath, "/") != 0)
            {
                strcat(newPath, "/");
            }
            saveTreeHelper(pdata, file, newPath);

            pcur = pcur->next;
        }
    }
}