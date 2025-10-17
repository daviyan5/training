get_filename_component(dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB SOURCES "*.cpp")
message(STATUS "Found source files in ${dir}: ${SOURCES}")

foreach(source_file ${SOURCES})
    message(STATUS "Processing source file: ${source_file}")
    get_filename_component(lib_name ${source_file} NAME_WE)

    set(full_lib_name "${dir}_${lib_name}")
    add_library(${full_lib_name} ${source_file})
    install(TARGETS ${full_lib_name} DESTINATION lib)
endforeach()
