#include <stdio.h>
#include <stdlib.h>

struct binaryTree
{
    int info;
    struct binaryTree *left;
    struct binaryTree *right;
};

typedef struct binaryTree node;

node *start = NULL;

// Function to create a new node
node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->info = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
node *insert(node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->info)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->info)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inserting a node at the beginning
void insert_nodes()
{
    int value;
    printf("Enter the data to be stored: ");
    scanf("%d", &value);
    start = insert(start, value);
}

// Traversing the tree in preorder
void traverse_preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}

// Traversing the tree in inorder
void traverse_inorder(node *root)
{
    if (root != NULL)
    {
        traverse_inorder(root->left);
        printf("%d ", root->info);
        traverse_inorder(root->right);
    }
}

// Traversing the tree in postorder
void traverse_postorder(node *root)
{
    if (root != NULL)
    {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d ", root->info);
    }
}

node *delete_node(node *root)
{
    if (root == NULL)
    {
        printf("There's no node to delete.\n");
    }
    else
    {
        node *temp = root;
        root = root->right;
        free(temp);
        printf("Node is deleted.\n");
    }

    return root;
}

// Searching for a node with a given value
node *search(node *root, int value)
{
    if (root == NULL || root->info == value)
    {
        return root;
    }

    if (value < root->info)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

void searching()
{
    int value;
    printf("Enter the value to search: ");
    scanf("%d", &value);

    node *result = search(start, value);

    if (result != NULL)
    {
        printf("Node with value %d found in the tree.\n", value);
    }
    else
    {
        printf("Node with value %d not found in the tree.\n", value);
    }
}

int main()
{
    int option_status = 1;
    int choose;
    while (option_status)
    {
        printf("\n==> MENU <==\n 1. INSERT NODES\n 2. TRAVERSE IN INORDER \n 3. TRAVERSE IN PREORDER\n 4. TRAVERSE IN POSTORDER \n 5. DELETE NODE \n 6. SEARCH \n 7. EXIT \n ------------------------- \n");
        printf("Choose one option: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            insert_nodes();
            break;
        case 2:
            printf("In-order traversal: ");
            traverse_inorder(start);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            traverse_preorder(start);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal: ");
            traverse_postorder(start);
            printf("\n");
            break;
        case 5:
            start = delete_node(start);
            break;
        case 6:
            searching();
            break;
        case 7:
            option_status = 0;
            printf("Exited!!!!\n");
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}
