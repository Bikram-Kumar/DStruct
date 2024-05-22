
#include "main.h"


int main() {
    
    LinkedList ll;
    printf("%d", ll.val+8);
    init_linked_list(&ll);
    printf("%d", ll.val);
    return 0;
}