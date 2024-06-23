
# revert list separator change
string(REPLACE "&" ";" allIncludes ${allIncludes})


execute_process(
    COMMAND ${CMAKE_COMMAND} -E make_directory ${binDir}/include/DStruct
)

foreach(header ${allIncludes})
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${header}" "${binDir}/include/DStruct/"
    )
endforeach()

