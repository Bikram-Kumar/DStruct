
#include "main.h"
#define NEW(x) malloc(sizeof(x))

void print(DLinkedList* this) {
    printf("DLinked List: ");
    
    while (1) {
        printf("%d ", this->val);
        if (this->next == NULL) {
            break;
        }
        this = this->next;
    }
    printf("\nReverse List: ");
    
    while (1) {
        printf("%d ", this->val);
        if (this->prev == NULL) {
            break;
        }
        this = this->prev;
    }

  
    printf("\n");
}



int main() {
    
    DLinkedList *ll = NEW(DLinkedList);
    init_dlinked_list(ll);
    ll->add(ll, NEW(DLinkedList), 8);
    ll->add(ll, NEW(DLinkedList), 9);
    ll->add(ll, NEW(DLinkedList), 76);
    ll->add(ll, NEW(DLinkedList), 59);
    ll->insert(ll, NEW(DLinkedList), 2, 800);
    
    printf("Size: %d\n", ll->size(ll));
    print(ll);
    printf("Index of 76: %d\n", ll->find(ll, 76));
    ll->remove(ll, ll->find(ll, 800));
    
    printf("Size after removing 800: %d\n", ll->size(ll));
    print(ll);
    printf("Index of 76: %d\n", ll->find(ll, 76));
    
    return 0;
}