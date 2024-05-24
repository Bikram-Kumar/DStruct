
#include "main.h"
#define NEW(x) malloc(sizeof(x))

void print(Stack* this) {
    printf("Stack: ");
    for (int i = 0; i < this->top; i++) {
        printf("%d ", *(this->arr + i));
    }
  
    printf("\n");
}



int main() {
    Stack* s = NEW(Stack);
    init_stack(s,4);
    print(s);
    s->pop(s);
    print(s);
    s->push(s,8);
    print(s);
    s->push(s,3);
    print(s);
    s->push(s,0);
    print(s);
    printf("%d\n", s->push(s,3));
    print(s);
    s->push(s,6);
    print(s);
    s->push(s,6);
    print(s);
    printf("%d\n", s->push(s,6));
    print(s);
    printf("%d\n", s->pop(s));
    print(s);
    s->pop(s);
    print(s);
    s->pop(s);
    print(s);
    s->pop(s);
    print(s);
    printf("%d\n", s->pop(s));
    print(s);
    return 0;
}