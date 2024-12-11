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
void add_at_pos(struct node* head , int data , int pos){
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;
    while(pos != 2){
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
} 
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_to_end(ptr , 39);
    ptr = add_to_end(ptr , 78);
    ptr = add_to_end(ptr , 89);

    int data = 3 , position = 3;
    add_at_pos(head , data , position);
    ptr = head;
    while(ptr != NULL){
        printf("%d\n" , ptr->data);
        ptr = ptr->link;
    }
    return 0;
}