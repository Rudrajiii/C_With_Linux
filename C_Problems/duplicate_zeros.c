#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkIfZeroExists(int arr[] , int arrSize){
    bool boolean = true;
    for(int i = 0 ; i < arrSize ; i++){
        if(arr[i] == 0){
            boolean = false;
            break;
        }
    }
    return boolean;
}
void duplicateZeros(int* arr, int arrSize){

    int j = 0;

    int* res = (int*)malloc(2 * arrSize * sizeof(int));
    if (res == NULL) {
        return;
    }

    for(int i = 0; i < arrSize && j < 2 * arrSize; i++){
        if(arr[i] != 0){
            res[j++] = arr[i];
        } else {
            res[j++] = 0;       
            if (j < 2 * arrSize) {
                res[j++] = 0;
            }
        }
    }

    for(int i = 0; i < arrSize; i++){
        arr[i] = res[i];
    }

    free(res);
}
