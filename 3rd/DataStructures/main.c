
#include "main.h"
#define NEW(x) malloc(sizeof(x))

void print(Queue* this) {
    printf("Queue: ");
    
    for (int i = 0; i < this->size; i++) {
        printf("%d ", *(this->arr + ((this->front + i) % this->capacity)));
    }
   
  
    printf("\n");
}



int main() {
    Queue* q = NEW(Queue);
    init_queue(q,4);
    int n;
    while (1) {
        scanf("%d", &n);
        int j,k;
        if (n == 1) {
            scanf("%d", &k);
            j = q->enqueue(q, k);
        } else {
            j = q->dequeue(q);
        }
        printf("%d\n", j);
        print(q);
    }
   
    
    return 0;
}