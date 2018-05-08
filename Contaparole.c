#include <stdio.h>

int main()
{
    int counter = 0;
    char c;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n'){
            ++counter; 
        }
    }
    printf("%d\n", counter);
    return 0;
}