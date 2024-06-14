
#include "main.h"



void print_arr(char* mess, BinarySearchTree** arr, BinarySearchTree** end) {
    printf("%s", mess);
    while (arr < end) {
        printf("%d ", (*arr)->get_val(*arr));
        arr++;
    }
    printf("\n");
}





int main() {
    BinarySearchTree* t = create_binary_search_tree(4);
    
    t->add_to_tree(t, create_binary_search_tree(1));
    t->add_to_tree(t, create_binary_search_tree(-6));
    t->add_to_tree(t, create_binary_search_tree(2));
    t->add_to_tree(t, create_binary_search_tree(-4));
    t->add_to_tree(t, create_binary_search_tree(4));
    t->add_to_tree(t, create_binary_search_tree(3));
    t->add_to_tree(t, create_binary_search_tree(0));
    t->add_to_tree(t, create_binary_search_tree(2));
     printf("root: %d\n", t->get_val(t));
     printf("root.left.right: %d\n", t->get_val(t->get_right(t->get_left(t))));
     printf("size: %d\n", t->get_size(t));

    
    
    BinarySearchTree** arr = malloc(sizeof(BinarySearchTree*) * t->get_size(t));
    
    t->traverse_bfs(t, arr);
    print_arr("bfs: ", arr, arr + t->get_size(t));
    
    t->traverse_pre(t, arr);
    print_arr("pre: ", arr, arr + t->get_size(t));
    
    t->traverse_in(t, arr);
    print_arr("in: ", arr, arr + t->get_size(t));
    
    t->traverse_post(t, arr);
    print_arr("post: ", arr, arr + t->get_size(t));
    
    t->destroy(t);
    free(arr);
  
    
    return 0;
}