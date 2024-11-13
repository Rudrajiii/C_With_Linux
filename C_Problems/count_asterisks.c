#include <stdio.h>
#include <stdbool.h>
int countAsterisks(char* s) {
    int count = 0;
    bool check_pipe = true;
    for(int i = 0 ; i < strlen(s) ; i++){
        if(check_pipe && s[i] == '*') count += 1;
        if(s[i] == '|') check_pipe = !check_pipe;
    }
    return count;
}