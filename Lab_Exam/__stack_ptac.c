#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct{
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool push(Stack *stack , int item);
bool pop(Stack *stack , int *item);
bool peek(Stack *stack , int *item);
void display(Stack *stack);

int main(){
    Stack *stack = create_stack(5);
    if(stack == NULL){
        printf("Error creating stack\n.");
        return 1;
    }
    if(is_empty(stack)) printf("Stack is empty\n.");
    push(stack, 2);
    printf("Stack size: %d\n", stack->size);
    
    // push 4 more items onto the stack, which should now be full
    push(stack, 9);
    push(stack, 4);
    push(stack, 7);
    push(stack, 8);
    display(stack);
    bool try_push = push(stack , 12);
    if(try_push == false) printf("Push failed.\n");
    int peek_value = 0;
    peek(stack , &peek_value);
    printf("Pick Value: %d\n", peek_value);

    int pop_value = 0;
    for(int i = 0 ; i < 5 ; i++){
        pop(stack , &pop_value);
        printf("Popped Value: %d\n", pop_value);

    }

    // if we try to pop an item off an empty stack, it will fail
  bool try_pop = pop(stack, &pop_value);
  if (try_pop == false) printf("Pop Failed.\n");
  
  // if we try to peek at an item on an empty stack, it will fail
  bool try_peek = peek(stack, &peek_value);
  if (try_peek == false) printf("Peek Failed.\n");

  destroy_stack(stack);

  return 0;
}

Stack *create_stack(int capacity){

    if(capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if(stack->collection == NULL){
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;

    return stack;

}
void destroy_stack(Stack *stack){

    free(stack->collection);
    free(stack);
}
bool is_full(Stack *stack){

    return stack->capacity == stack->size;
}
bool is_empty(Stack *stack){

    return stack->size == 0;
}
bool push(Stack *stack , int item){

    if(is_full(stack)) return false;

    stack->collection[stack->size] = item;
    stack->size++;

    return true;

}
bool peek(Stack *stack , int *item){

    if(is_empty(stack)) return false;

    *item = stack->collection[stack->size - 1];
    return true;

}
bool pop(Stack *stack , int *item){

    if(is_empty(stack)) return false;
    stack->size--;
    *item = stack->collection[stack->size];
    return true;

}
void display(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (from bottom to top): ");
    for (int i = 0; i < stack->size; i++) {
        printf("%d ", stack->collection[i]);
    }
    printf("\n");
}
