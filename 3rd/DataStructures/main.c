
#include "main.h"


int main() {
    
    LinkedList ll;
    printf("%d\n", ll.val+8);
    init_linked_list(&ll);
    printf("%d\n", ll.val);
    return 0;
}