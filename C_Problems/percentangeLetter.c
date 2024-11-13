
int percentageLetter(char* s, char letter) {
    int count = 0;
        for(int i = 0 ; i < strlen(s) ; i++){
            if(s[i] == letter) count++;
        }
        double eq =  (double) count / strlen(s) * 100;
        return (int)eq;
}