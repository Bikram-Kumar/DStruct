
#include "main.h"
#define NEW(x) malloc(sizeof(x))

void print(Stack* this) {
    printf("stack: ");
    
    for (int i = 0; i < this->top; i++) {
        printf("%d ", *(this->arr + i));
    }
   
  
    printf("\n");
}



int main() {
    Stack* q = NEW(Stack);
    init_stack(q,4);
    int n,j,k;
    while (1) {
        scanf("%d", &n);
        
        if (n == 1) {
            scanf("%d", &k);
            j = q->push(q, k);
        } else if (n == 2) {
            j = q->pop(q);
        } else if (n == 3) {
            j = q->peek(q);
        } 
        
        printf("%d\n", j);
        print(q);
    }
   
    
    return 0;
}