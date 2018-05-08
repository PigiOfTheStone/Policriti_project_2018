#include <stdio.h>

int main()
{
    long length;
    length = 0;
    char c;
    while((c = getchar()) != EOF){
        if(c != ' ' && c != '\n'){
           //++length;
           printf("-");
        }else{
            printf("\n");
        }  
    }
    //printf("%ld\n", number_whitespace);
    return 0;
}