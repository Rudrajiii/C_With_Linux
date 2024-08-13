#include <stdio.h>

int max(int num1, int num2);
int min(int num1, int num2);

int main(){
    
    int water_level[] = {1 , 5 , 6 , 3 , 4};
    int length = sizeof(water_level) / sizeof(water_level[0]);
    int left_pointer = 0;
    int right_pointer = length - 1;

    int max_area = 0;
    int new_area;
    while(left_pointer < right_pointer){
        new_area = min(water_level[left_pointer] , water_level[right_pointer]) * (right_pointer - left_pointer);
        max_area = max(max_area , new_area);
        
        if(water_level[left_pointer] < water_level[right_pointer]) left_pointer++;
        else right_pointer--;
    }
    
    printf("Max Area Obtained : %d\n" , max_area);
    return 0;

}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

