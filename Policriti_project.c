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
void print_bst(NODE* n);

int main(){
    NODE* root = NULL;
    root = bst_insert(root, 'c');
    root = bst_insert(root, 'a');
    root = bst_insert(root, 'z');

    print_bst(root);
    return 0;
    
}

NODE* bst_insert(NODE* n, char key){
    if(n == NULL){
        n = (NODE*)malloc(sizeof(NODE)); //Allocato memoria per n
        n->key = key;
        n->left = NULL;
        n->right = NULL;
        return n;
        
    }else{
        if(n->key > key){
            if(n->left == NULL){
                n->left = bst_insert(n->left, key);
                return n;
            }else{
                return bst_insert(n->left, key);
            }
        }else{
            if(n->right == NULL){
                n->right = bst_insert(n->right, key);
                return n;
            }else{
                return bst_insert(n->right, key);
            }
        }
    }
}

void print_bst(NODE* n){
    if(n != NULL){
        print_bst(n->left);
        printf("%c ", n->key);
        print_bst(n->right);
    }
}

