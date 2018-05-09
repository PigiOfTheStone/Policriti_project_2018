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

int main(){

    NODE* root = read_input();
    bst_print(root);
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
    char c = getchar();
    NODE* root = NULL;
    while('a'<= c && c <= 'z'){
        root = bst_insert(root, c);
        c = getchar(); 
    }
    return root;
}
