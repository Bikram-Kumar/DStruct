
#include "main.h"



void print_arr(char* mess, Heap** arr, Heap** end) {
    printf("%s", mess);
    while (arr < end) {
        printf("%d ", (*arr)->get_val(*arr));
        arr++;
    }
    printf("\n");
}





int main() {

    Heap* t = create_heap(4);
    
    t = t->push(t, create_heap(1));
    t = t->push(t, create_heap(8));
    t = t->push(t, create_heap(0));
    t = t->push(t, create_heap(156));
    t = t->push(t, create_heap(-3));
    t = t->push(t, create_heap(-7));
    t = t->push(t, create_heap(4));
    t = t->push(t, create_heap(-39));
    t = t->push(t, create_heap(75));
    
     
    
    Heap** arr = malloc(sizeof(Heap*) * t->get_size(t));
    
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