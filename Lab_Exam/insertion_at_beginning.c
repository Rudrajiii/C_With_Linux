#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_beg(struct node *head , int d){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}

int main(){

    struct node *head = malloc(sizeof(struct node));
    head->data = 20;
    head->link = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 98;
    ptr->link = NULL;

    head->link = ptr;
    int d = 3;
    head = add_beg(head , d);
    ptr = head;
    printf("%p\n" , head);
    while(head != NULL){
        printf("%d\n" , head->data);
        head = head->link;
    }
    printf("%p\n" , head);
    head = ptr;
    printf("%p" , head);
    return 0;
}

