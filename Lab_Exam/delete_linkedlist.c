#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node* add_to_end(struct node *ptr , int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

struct node* del(struct node* head){
    struct node* temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_to_end(ptr , 39);
    ptr = add_to_end(ptr , 78);
    ptr = add_to_end(ptr , 89);
    ptr = head;
    while(ptr != NULL){
        printf("%d\n" , ptr->data);
        ptr = ptr->link;
    }
    head = del(head);
    printf("------------------------\n");
    ptr = head;
    while(ptr != NULL){
        printf("%d\n" , ptr->data);
        ptr = ptr->link;
    }
    return 0;
}