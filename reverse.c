#include <stdio.h>



int main(){
    char string[100000];
    char c;
    int count = 0;
    while((c = getchar()) != EOF){ //Inserisce la stringa nell'array string
        string[count] = c;
        ++count; 
    }
    string[count] = '\0';
    char rev_string[count];
    
    
    for(int i = 0; i < count; i++){
        rev_string[i] = string[count-i-1];
    }
    for(int i = 0; i < count; i++){
        printf("%c",rev_string[i]);
    }
}


