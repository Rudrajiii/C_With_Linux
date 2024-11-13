#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* capitalizeTitle(char* title) {
    char *words[1000]; 
    int index = 0;   
    char *token = strtok(title, " ");  
    
    while (token != NULL) {
        words[index++] = token; 
        token = strtok(NULL, " "); 
    }
    int total_length = 0;
    for (int i = 0; i < index; i++) {
        total_length += strlen(words[i]);
        if (i < index - 1) {
            total_length++;
        }
    }

    char *updated_title = (char *)malloc((total_length + 1) * sizeof(char)); 
    if (updated_title == NULL) {
        return NULL; 
    }
    updated_title[0] = '\0';

    for (int i = 0; i < index; i++) {
        if (strlen(words[i]) > 2) {
            words[i][0] = toupper(words[i][0]); 
            for (int j = 1; j < strlen(words[i]); j++) {
                words[i][j] = tolower(words[i][j]);
            }
        } else {
            for (int j = 0; j < strlen(words[i]); j++) {
                words[i][j] = tolower(words[i][j]); 
            }
        }
    }
    for (int i = 0; i < index; i++) {
        strcat(updated_title, words[i]);
        if (i < index - 1) {
            strcat(updated_title, " ");
        }
    }
    return updated_title;
}