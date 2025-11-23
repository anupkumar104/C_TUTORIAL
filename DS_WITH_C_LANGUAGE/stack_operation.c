#include <stdio.h>
#include <stdlib.h>

struct node {  
    int info;
    struct node *link;  
} *top = NULL;

void push(int item);
int pop();
int isempty(); 
void display(); 

int main() {  
    int choice, item;  
    while (1) {
        printf("1 Push\n");
        printf("2 Pop\n");
        printf("3 Display all items of stack\n");
        printf("4 Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {  
            case 1:  
                printf("Enter item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:  
                item = pop();
                printf("Popped item is %d\n", item); 
                break;
            case 3:  
                display();
                break;
            case 4: 
                exit(0);  
            default:  
                printf("Wrong choice\n");
        }
    }
    return 0;  
}

void push(int item) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));  
    if (temp == NULL) {
        printf("Stack overflow\n");
        return;
    }
    temp->info = item;
    temp->link = top;
    top = temp;
}

int pop() {
    struct node *temp;
    int item;
    if (isempty()) {  
        printf("Stack Underflow\n");
        exit(1);
    }
    temp = top;
    item = temp->info;
    top = top->link;
    free(temp);
    return item;
}

int isempty() {  
    if (top == NULL)  
        return 1;
    else
        return 0;
}

void display() {  
    struct node *ptr;
    ptr = top;
    if (isempty()) {
        printf("Stack is empty\n");  
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->info);  
        ptr = ptr->link;
    }
    printf("\n"); 
}
