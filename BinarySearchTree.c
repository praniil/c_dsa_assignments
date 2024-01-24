#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *Left, *Right;
} Node;

// Node insertNode(int data, struct Node *Left, struct Node *Right)
// {
//     Node *root;
//     root->data = data;
//     root->Left = Left;
//     root->Right = Right;
//     return *root;
// }

// struct Node* insertNode(struct Node *root, int len)
// {
//     Node *root;
//     for (int i = 0; i < len; i++)
//     {
//         root->data = data[i];
//         if (data[i + 1] < data[i])
//         {
//             root->Left->data = data[i + 1];
//             root->data = root->Left->data;
//         }
//         else if (data[i + 1] > data[i])
//         {
//             root->Right->data = data[i + 1];
//             root->data = root->Right->data;
//         }
//     }
//     printf("%d", root->data);
//     printf("%d", root->Left->data);
//     printf("%d", root->Right->data);
// }

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

struct Node *insertNode (struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root-> data) {
        root -> Left = insertNode(root->Left, data);
    } else if(data > root -> data) {
        root -> Right = insertNode(root -> Right, data);
    }
    return root;
}

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

    struct Node *root = NULL;
      root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("preOrder Traverse: ");
    preOrderTraverse(root);
    printf("\n");

    printf("inOrder Traverse: ");
    inOrderTraverse(root);
    printf("\n");

    printf("postOrder Traverse: ");
    postOrderTraverse(root);
    printf("\n");

    // Free the allocated memory
    // free(root.Left->Right);
    // free(root.Left);
    // free(root.Right->Right);
    // free(root.Right);

    return 0;
}
