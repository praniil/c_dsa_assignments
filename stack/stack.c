#include<stdio.h>
#define size 20

struct Stack {
    int array[size];
    int top;
};

void push(struct Stack *s, int value){
    if (s->top == size) {
        printf("stack full.\n");
    }
    else {
        s->top = s-> top + 1;
        s->array[s->top] = value;
        // s->top = s->top + 1;
    }
}

void pop(struct Stack *s) {
    if (s-> top == -1) {
        printf("stack empty\n");
    } 
    else{
        printf("the element popped: %d\n", s->array[s->top]);
        s->top = s->top - 1;
    }
}

void display(struct Stack *s) {
    printf("the elements in the stack are: \n");
    if(s->top == -1) {
        printf("the stack is empty: \n");
    } 
    else{
    for(int i=0; i <= s->top; i++) {
        printf("%d \n", s->array[i]);
    }
    }
}

void displayTop(struct Stack *s){
    if (s->top == -1) {
        printf("no element to display \n");
    } else{
        printf("the element in the top is: %d", s->array[s->top]);
    }
}

int main(){
    struct Stack s;
    int value;
    s.top = -1;
    int choice;
    int i = 1;
    while(i) {

    printf("1.for push, 2.for pop, 3.Display all elements 4.displaytTop");
    printf("enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("enter the value you want to push: ");
        scanf("%d", &value);
        push(&s, value);
        break;
    case 3:
        display(&s);
        break;
    case 4:
        displayTop(&s);
        break;
    case 5:
        i = 0;
        break;
    default:
        break;
    }
    }
}