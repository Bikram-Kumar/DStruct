
#include "main.h"
#define NEW(x) malloc(sizeof(x))


void print_child (Tree* t) {
    for (int i = 0; i < t->degree; i++) {
        printf("%d ", t->children[i]->val);
    }
}


void print(Tree* t) {
    print_child(t);
    printf("\n");
    for (int i = 0; i < t->degree; i++) {
        print_child(t->children[i]);
        printf(" ");
    }
    printf("\n");
    
}

void print_arr(Tree** arr, Tree** end) {
    printf("Arr: ");
    while (arr < end) {
        printf("%d ", (*arr)->val);
        arr++;
    }
    printf("\n");
}





int main() {
    Tree* t = init_tree(NEW(Tree), 0, 2);
    t->set_child(t, 0, init_tree(NEW(Tree), 1, 2));
    t->set_child(t->children[0], 0, init_tree(NEW(Tree), 3, 0));
    t->set_child(t->children[0], 1, init_tree(NEW(Tree), 4, 0));
    
    t->set_child(t, 1, init_tree(NEW(Tree), 2, 3));
    t->set_child(t->children[1], 0, init_tree(NEW(Tree), 5, 0));
    t->set_child(t->children[1], 1, init_tree(NEW(Tree), 6, 0));
    t->set_child(t->children[1], 2, init_tree(NEW(Tree), 7, 0));
    
    
    
    printf("size: %d\n", t->size);
    printf("%d\n", t->val);
    print(t);
    
    
    
    Tree** arr = malloc(sizeof(Tree*) * t->size);
    t->traverse_pre(t, arr);
    print_arr(arr, arr+t->size);
    
    t->traverse_post(t, arr);
    print_arr(arr, arr+t->size);
    
    free(arr);
    
    return 0;
}