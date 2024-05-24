cmake_minimum_required(VERSION 3.10)

project(DataStructures)

add_executable(
    DataStructures 
    main.c
    LinkedList/linked_list.c
    Arrays/arrays.c
    
)


# target_include_directories(DataStructures PRIVATE "${PROJECT_BINARY_DIR}")


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