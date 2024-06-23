
## INTRODUCTION 

The library contains the following type definitions:
* DArray
* LinkedList
* DLinkedList
* Stack
* GStack
* Queue
* GQueue
* Deque
* Tree
* BTree
* BSTree
* AVLTree
* Heap
* Graph

To use, `#include` the corresponding header file, named the same in lowercase like, `#include "DStruct/bstree.h"`

You can create an instance of a type by using `create_TYPE()` functions, which returns the pointer to the instance. `create_TYPE()` allocates memory
on heap using `malloc()` functions, so you must call the corresponding `destroy_TYPE()`, to free up the allocated memory, when you are done with it.
DO NOT use `free()` on the pointer returned by `create` functions; there are other dynamic memory allocations inside the struct, which also needs to be freed.

The functions for each type are named with lowercase prefix of the type i.e., `typename_function_name()`. For decreasing verbosity, each struct contains
pointers to their respective type functions, which you can access omitting the typename. For example,`gstack_push(s, num)` can be called by `s->push(s, num)`.
Both functions are the same and should be used as per convenience.
