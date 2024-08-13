#include<stdio.h>
 
int linearscearch(int arr[],int l,int key); 
void checkresult(int r); 
int main(){ 
    int arr[]={1,3,4,6,7}; 
    int l=5; 
    int key; 
    printf("Enter the searchable elements of the array:\n "); 
    scanf("%d",&key); 
    int r=linearscearch(arr,l,key); 
    checkresult(r); 
    return 0; 
} 
int linearscearch(int arr[],int l,int key){ 
    int i; 
    int find=0; 
    for(i=0;i<l;i=i+1){ 
        if(arr[i]==key){ 
            find=i; 
        } 
    } 
    return find; 
} 
void checkresult(int r){ 
    if(r==0){ 
        printf("Element is not found"); 
    }else{ 
        printf("Element is found at the posi on %d\n",r); 
    } 
} 
