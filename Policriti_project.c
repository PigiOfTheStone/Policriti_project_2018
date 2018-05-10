#include <stdio.h>
#include <stdlib.h>

//Struct BST
typedef struct node NODE;
struct node 
{
    char key;
    struct node *left;
    struct node *right;
    struct node *father;
};

//Struct Lista di adiacenza per grafo
typedef struct list_node LIST_NODE;
struct list_node
{
    struct node *next;
    struct NODE *position; //Posizione della foglia nell'albero
};

//Prototipi
NODE* bst_insert(NODE* n, char key);
void bst_print(NODE* n);
NODE* read_input();
int max(int* counter);
int min(int* counter);
NODE* bst_search_for_leaf(NODE* root, char key);
LIST_NODE* create_list();
LIST_NODE* add_to_list(char key, LIST_NODE* last);

//Variabili globali 
int M;
int m;

int main(){

    LIST_NODE* list = NULL; //Puntatore alla lista vuota delle adiacenze
    NODE* root = read_input();
    bst_search_for_leaf(root, list);

    bst_print(root);
    //printf("\nMin: %d\nMax: %d\n", m, M);


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

int max(int* counter){ //Calcola il valore di M i.e. il numero massimo di occorrenze del carattere che si ripete di più nella stringa 
    int max_int = counter[0];
    for(int i = 0; i < 26; i++){
        if(counter[i] > max_int){
            max_int = counter[i];
        }
    }
    return max_int;
}

int min(int* counter){ //Calcola il valore di m i.e. il numero minimo di occorrenze del carattere che si ripete di meno nella stringa
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

LIST_NODE* bst_search_for_leaf(NODE* root, LIST_NODE* last){ //Cerca nel BST i nodi che sono foglia e chiama il creatore di lista di adiacenza
    if(root != NULL){
        if(root->left == NULL & root->right == NULL){
            last = add_to_list(root, last);
        }else{
            last = bst_search_for_leaf(root->left, last);
            last = bst_search_for_leaf(root->right, last);
        }
    }

    return last;
}

LIST_NODE* add_to_list(NODE* leaf, LIST_NODE* last){
    if(last == NULL){
        last = (LIST_NODE*)malloc(sizeof(LIST_NODE));
        last->position = leaf;
        last->next = NULL;
    }else{
        last->next = (LIST_NODE*)malloc(sizeof(LIST_NODE));
        last->next->position = leaf;
        last->next->next = NULL;
        last = last->next;
    }
    return last;
}

/* 
if(last != NULL){
    last = last->next;
}

last = malloc...
last->next=null
last->value=key;

return last;
 */