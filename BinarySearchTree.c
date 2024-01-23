#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *Left, *Right;
} Node;

void inOrderTraverse(struct Node *node)
{
    if (node != NULL)
    {
        inOrderTraverse(node->Left);
        printf("%d ", node->data);
        inOrderTraverse(node->Right);
    }
}

void preOrderTraverse(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrderTraverse(node->Left);
        preOrderTraverse(node->Right);
    }
}

void postOrderTraverse(struct Node *node)
{
    if (node != NULL)
    {
        postOrderTraverse(node->Left);
        postOrderTraverse(node->Right);
        printf("%d ", node->data);
    }
}

int main()
{
    struct Node root;
    root.data = 5;
    
    root.Left = (struct Node *)malloc(sizeof(struct Node));
    root.Left->data = 6;
    root.Left->Left = NULL;
    root.Left->Right = (struct Node *)malloc(sizeof(struct Node));
    root.Left->Right->data = 7;
    root.Left->Right->Left = NULL;
    root.Left->Right->Right = NULL;
    
    root.Right = (struct Node *)malloc(sizeof(struct Node));
    root.Right->data = 8;
    root.Right->Left = NULL;
    
    root.Right->Right = (struct Node *)malloc(sizeof(struct Node));
    root.Right->Right->data = 9;
    root.Right->Right->Left = NULL;
    root.Right->Right->Right = NULL;

    printf("preOrder Traverse: ");
    preOrderTraverse(&root);
    printf("\n");

    printf("inOrder Traverse: ");
    inOrderTraverse(&root);
    printf("\n");

    printf("postOrder Traverse: ");
    postOrderTraverse(&root);
    printf("\n");

    // Free the allocated memory
    free(root.Left->Right);
    free(root.Left);
    free(root.Right->Right);
    free(root.Right);

    return 0;
}
