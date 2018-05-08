#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000 //Lunghezza massima di una linea

int readline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int length; //Lunghezza della linea corrente
    int max; //Massima lunghezza trovata finora
    char line[MAXLINE]; //Linea di input corrente
    char longest[MAXLINE]; //Linea più lunga corrente

    max = -1;
    while((length = readline(line, MAXLINE)) >= 0){
        if(length > max){
            max = length;
            copy(longest, line);
        }
    }
    if(max >= 0){ //C'era almeno una linea in input
        printf("La stringa più lunga è: %s\n", longest);
    }
    return 0;
}

int readline(char line[], int maxline){
   // printf("Ciao marietto sono dentro\n");
    char c;
    int length_line = 0;
     c = getchar();
     //printf("%c", c);
    do{
       if(c != '\n' && c != EOF){
            line[length_line] = c;
            ++length_line;
            c = getchar();
            //printf("%c", c);
        }
    }while(c != '\n' && c != EOF && length_line < maxline);

    if(length_line == 0){
        return -1;
    }
    line[length_line] = '\0';
    //fprintf(stderr, "UE %d %s\n", length_line, line);
    
    return length_line;
}

void copy(char to[], char from[]){
    char c;
    int counter = 0;
    while((c = from[counter]) != '\0'){
        to[counter] = from[counter];
        ++counter;
    }
    to[counter] = '\0';
}