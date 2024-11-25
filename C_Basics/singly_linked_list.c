#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;     
};
//* Time Complexity : O(n)
void add_to_end(struct node *head , int data){
    if(head == NULL){
        printf("LINKED LIST IS EMPTY");
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    struct node *ptr = NULL;
    ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void count_nodes(struct node *head){
    int count = 0;
    if(head == NULL){
        printf("LINKED LIST IS EMPTY");
    }
    struct node *ptr;
    ptr = head;
    while(ptr != NULL){
        count++;
        printf("VALUE [%d] = %d\n" , count , ptr->data);
        ptr = ptr->link;
    }
    printf("COUNT=%d\n",count);
}

int main(){
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    
    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 90;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 135;
    current->link = NULL;

    head->link->link = current;
    count_nodes(head);
    add_to_end(head , 67);
    count_nodes(head);
    return 0;
}
