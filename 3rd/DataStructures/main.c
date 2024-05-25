
#include "main.h"
#define NEW(x) malloc(sizeof(x))

void print(Deque* this) {
    printf("Deque: ");
    
    for (int i = 0; i < this->size; i++) {
        printf("%d ", *(this->arr + ((this->front + i) % this->capacity)));
    }
   
  
    printf("\n");
}



int main() {
    Deque* q = NEW(Deque);
    init_deque(q,4);
    int n,j,k;
    while (1) {
        scanf("%d", &n);
        
        if (n == 1) {
            scanf("%d", &k);
            j = q->push_front(q, k);
        } else if (n == 2) {
            j = q->pop_front(q);
        } else if (n == 3) {
            scanf("%d", &k);
            j = q->push_back(q, k);
        } else if (n == 4) {
            j = q->pop_back(q);
        }
        
        printf("%d\n", j);
        print(q);
    }
   
    
    return 0;
}