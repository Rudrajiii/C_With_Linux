#include <stdio.h>
int custom_stack[20];
//our custom push function
void push(int *top , int val){
	int n = sizeof(custom_stack) / sizeof(custom_stack[0]);
	if((*top) == n - 1){
		printf("Unable To Push\n");
	}else{
		custom_stack[++(*top)] = val;
	}
}
//our custom display func
void display(int top){

	for(int i = 0 ; i <= top ; i++){
		printf("\n%d\n" , custom_stack[i]);
	}

}
//our custom pop func
int pop(int *top){
	if((*top) == -1){
		printf("Stack is Emplty\n");
	}else{
		int val = custom_stack[(*top)--];
		return val;
	}
}
//our custom pick func
int pick(int *top){
	if((*top) == -1){
		printf("Stack is Empty\n");
	}else{
		int val = custom_stack[*top];
		return val;
	}
}
int main(){
	int top = -1;
	int n , item , count = 1;
	printf("ENTER THE NO OF ITEM YOU WANT IN STACK ==> ");
	scanf("%d" , &n);
	while(n > 0){
		printf("%d ) Insert -> " , count);
		scanf("%d", &item);
		push(&top , item);
		count += 1;
		n -= 1;
	}

	printf("AFTER INSERTING ITEM\n");
	display(top);

	printf("AFTER ITEM POPED UP\n");
	pop(&top);
	display(top);

	printf("PICKED VALUE\n");
	int picked_value = pick(&top);
	if(picked_value != -1){
		printf("picked value is%d\n",picked_value);
	}
	return 0;

}	

