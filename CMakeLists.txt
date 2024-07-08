cmake_minimum_required(VERSION 3.10)
project(StackTests)

set(CMAKE_CXX_STANDARD 11)

# Ruta a los archivos de encabezado de Google Test
include_directories(C:/Users/aloza/googletest/googletest/include)

# Ruta a los archivos de biblioteca de Google Test
link_directories(C:/Users/aloza/googletest/build/lib/Release)

# Configurar la construcción para usar la misma biblioteca de tiempo de ejecución
foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif()
endforeach()

# Ejecutable para las pruebas de stack
add_executable(test_stack 
    tests/test_stack.cpp
)

# Ejecutable para las pruebas de symbol table
add_executable(test_symbol_table 
    tests/test_symbol_table.cpp
    src/symbol_table.cpp
)

# Ejecutable para las pruebas de postfix evaluator
add_executable(test_postfix_evaluator 
    tests/test_postfix_evaluator.cpp
    src/postfix_evaluator.cpp
    src/symbol_table.cpp
)

# Enlazar con las bibliotecas de Google Test
target_link_libraries(test_stack gtest gtest_main)
target_link_libraries(test_symbol_table gtest gtest_main)
target_link_libraries(test_postfix_evaluator gtest gtest_main)