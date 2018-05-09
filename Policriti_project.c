#include <stdio.h>
#include <stdlib.h>

struct node 
{
    char key;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE* bst_insert(NODE* n, char key);
void bst_print(NODE* n);
NODE* read_input();
int max(int* counter);
int min(int* counter);
int M;
int m;

int main(){

    NODE* root = read_input();
    bst_print(root);
    printf("\nMin: %d\nMax: %d\n", m, M);


    return 0;
}

NODE* bst_insert(NODE* n, char key){ //Inserisce un nodo nel bst
    if(n == NULL){ //CASO BASE: primo inserimento
        n = (NODE*)malloc(sizeof(NODE)); //Allocato memoria per n
        n->key = key;
        n->left = NULL;
        n->right = NULL;
    }else if(n->key >= key){ //Valuto il sottoalbero sinistro
        n->left = bst_insert(n->left, key); //Chiamata ricorsiva a bst_insert con radice primo nodo del sottoalbero sinistro
    }else{ //Valuto il sottoalbero destro
        n->right = bst_insert(n->right, key); //Chiamata ricorsiva a bst_insert con radice primo nodo del sottoalbero destro
    }

    return n;
}

void bst_print(NODE* n){ //Stampa il bst inorder
    if(n != NULL){
        bst_print(n->left);
        printf("%c ", n->key);
        bst_print(n->right);
        
    }
}

NODE* read_input(){ //Legge la parola e lancia bst_insert per creare l'albero della parola
    int counter[26]; 
    for(int i = 0; i < 26; i++){
        counter[i] = 0;
    }
    char c = getchar();
    NODE* root = NULL;
    while('a'<= c && c <= 'z'){
        counter[c -'a'] += 1;  //Conta il numero di occorrenze di tutti i caratteri
        root = bst_insert(root, c);
        c = getchar(); 
        M = max(counter);
        m = min(counter);
    }

    return root;
}

int max(int* counter){
    int max_int = counter[0];
    for(int i = 0; i < 26; i++){
        if(counter[i] > max_int){
            max_int = counter[i];
        }
    }
    return max_int;
}

int min(int* counter){
    int min_int = counter[0];
    for(int i = 0; i < 26; i++){
        if(min_int == 0 && counter[i] != 0){
            min_int = counter[i];
        }
        if(counter[i] != 0 && counter[i] < min_int){
            min_int = counter[i];
        }
    }
    return min_int;
}