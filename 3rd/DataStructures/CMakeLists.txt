cmake_minimum_required(VERSION 3.10)

project(DataStructures)

set(
    LinearDirSources
    Stacks/stack.c
    Stacks/gstack.c
    Queues/queue.c
    Queues/gqueue.c
    Queues/deque.c
    LinkedLists/linkedlist.c
    LinkedLists/dlinkedlist.c
)

set(
    TreesDirSources
    tree.c
    Binary/btree.c
    Binary/bstree.c
    Binary/Heap/heap.c
)

list(TRANSFORM LinearDirSources PREPEND Linear/)
list(TRANSFORM TreesDirSources PREPEND Trees/)


add_executable(
    DataStructures 
    main.c
    "${LinearDirSources}"
    "${TreesDirSources}"
)

target_include_directories(
    DataStructures
    PUBLIC
    ./Linear/Stacks/
    ./Linear/Queues/
    ./Linear/LinkedLists/
    ./Trees/
    ./Trees/Binary/
    ./Trees/Binary/Heap/
    ./Graph/
)



if (WIN32)
    set(binExtension ".exe")
else ()
    set(binExtension ".out")
endif()

set_target_properties(
    DataStructures
    PROPERTIES
    OUTPUT_NAME "a"
    SUFFIX ${binExtension}
)