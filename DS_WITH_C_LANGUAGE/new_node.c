#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

void fun1(struct node* head) {
    if (head == NULL)
        return;
    fun1(head->next); 
    printf("%d ", head->data);  
}
struct node* newNode(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = data;  
    new_node->next = NULL;  
    return new_node;  
}
int main() {
    struct node* head = NULL;
    head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    fun1(head); 
    printf("\n");
    return 0;
}
