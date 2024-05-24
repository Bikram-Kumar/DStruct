
#include "main.h"
#define NEW(x) malloc(sizeof(x))

void print(LinkedList* this) {
    printf("Linked List: ");
    
    while (this != NULL) {
        printf("%d ", this->val);
        this = this->next;
    }
    printf("\n");
}



int main() {
    
    LinkedList *ll = NEW(LinkedList);
    init_linked_list(ll);
    ll->add(ll, NEW(LinkedList), 8);
    ll->add(ll, NEW(LinkedList), 9);
    ll->add(ll, NEW(LinkedList), 76);
    ll->add(ll, NEW(LinkedList), 59);
    ll->insert(ll, NEW(LinkedList), 2, 800);
    
    printf("Size: %d\n", ll->size(ll));
    print(ll);
    printf("Index of 76: %d\n", ll->find(ll, 76));
    ll->remove(ll, ll->find(ll, 800));
    
    printf("Size after removing 800: %d\n", ll->size(ll));
    print(ll);
    printf("Index of 76: %d\n", ll->find(ll, 76));
    
    return 0;
}