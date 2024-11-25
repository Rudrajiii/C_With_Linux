#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* insert(struct node *ptr , int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 20;
    head->link = NULL;

    struct node *ptr;
    ptr = head;
    for(int i = 3 ; i < 10 ; i++){
        ptr = insert(ptr , i*10);
    }

    ptr = head;
    while(ptr != NULL){
        printf("%d\n" , ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
