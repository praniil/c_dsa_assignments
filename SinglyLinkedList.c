#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (newNode != NULL)
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteLastNode(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", *((int *)temp));
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(Node *head, int key)
{
    Node *temp = head;
    int position = 0;

    while (temp != NULL)
    {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }
    return -1;
}

int main()
{
    Node *myList = NULL;
    insertAtBeginning(&myList, 5);
    insertAtBeginning(&myList, 10);
    insertAtBeginning(&myList, 15);
    printf("Linked List: ");
    printList(myList);
    deleteLastNode(&myList);
    printf("After deleting last node: ");
    printList(myList);

    int searchKey = 10;
    int position = search(myList, searchKey);
    if (position != -1)
    {
        printf("%d found at position: %d \n", searchKey, position);
    }
    else
    {
        printf("%d not found in the list.\n", searchKey);
    }
    Node *temp;
    while (myList != NULL)
    {
        temp = myList;
        myList = myList->next;
        free(temp);
    }
    return 0;
}