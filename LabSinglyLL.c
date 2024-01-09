#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info; 
    struct node *next;

} node;

node *start = NULL; 
void f_insert()
{
    node *item;
    item = (node *)malloc(sizeof(node));
    printf("Enter the data to insert: ");
    scanf("%d", &item->info); 

    if (start == NULL)
    {
        item->next = NULL;
        start = item;
    }
    else
    {
        item->next = start;
        start = item;
    }
}

void f_del()
{
    node *ptr, *loc;
    if (start == NULL)
    {
        printf("Empty list\n");
    }
    else if (start->next == NULL)
    {
        printf("Deleted element is %d\n", start->info);
        free(start);
        start = NULL;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            loc = ptr;
            ptr = ptr->next;
        }
        loc->next = NULL;
        printf("Deleted element is %d\n", ptr->info);
        free(ptr);
    }
}


void display()
{
    node *temp;
    printf("Elements of linked list are: ");
    temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}


void search()
{
    node *temp;
    int num, count = 0;
    printf("Enter a number to search: ");
    scanf("%d", &num);
    temp = start;
    while (temp != NULL)
    {
        count++;
        if (temp->info == num)
        {
            printf("This number is at position %d\n", count);
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    printf("This number does not exist in the list\n");
}

int main()
{
    int option_status = 1;
    int choose;
    while (option_status)
    {
        printf("\n==> MENU <==\n 1. INSERT \n 2. DELETE LAST NODE \n 3. DISPLAY ALL ELEMENTS\n 4. SEARCH \n 5. EXIT \n ------------------------- \n");
        printf("Choose one option: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            f_insert();
            break;
        case 2:
            f_del();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            option_status = 0;
            printf("Exited!!!!\n");
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}