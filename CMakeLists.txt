cmake_minimum_required(VERSION 3.10)

project(DStruct)



option(BUILD_SHARED_LIBS "Build shared library" OFF)
option(OUT_INCLUDES "Generate include folder with all headers" OFF)



set(
    ArraysDirSources
    darray.c
    garray.c
)


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

set(
    includeDirs
    ./Arrays/
    ./Linear/Stacks/
    ./Linear/Queues/
    ./Linear/LinkedLists/
    ./Trees/
    ./Trees/Binary/
    ./Trees/Binary/Heap/
    ./Graph/
)

list(TRANSFORM ArraysDirSources PREPEND ./Arrays/)
list(TRANSFORM LinearDirSources PREPEND ./Linear/)
list(TRANSFORM TreesDirSources PREPEND ./Trees/)

set(
    allSources
    
    
    ${ArraysDirSources}
    ${LinearDirSources}
    ${TreesDirSources}
)


add_library(
    DStruct 
    ${allSources}
)

target_include_directories(
    DStruct
    PUBLIC
    ${includeDirs}
)


if (OUT_INCLUDES)
    
    set(allIncludes ${allSources})
    
    list(TRANSFORM allIncludes REPLACE "c$" "h")
    list(APPEND allIncludes ./Arrays/darrayutils.h)
    
    # cmake replaces ';' with whitespace on passing list to the script so replace it with '&' and revert in script
    
    string(REPLACE ";" "&" allIncludesN "${allIncludes}")

    add_custom_command(
        TARGET DStruct
        POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -DallIncludes="${allIncludesN}" -DbinDir="${CMAKE_BINARY_DIR}" -P ./generate_includes.cmake
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        COMMENT "OUT_INCLUDES is ON. Generating include files in include/DStruct..."
    )
    

endif()
