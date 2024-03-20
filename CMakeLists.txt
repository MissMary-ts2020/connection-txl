cmake_minimum_required(VERSION 3.27)
project(txl_final_fxxku_iffiled_never)

set(CMAKE_CXX_STANDARD 17)

add_executable(txl_final_fxxku_iffiled_never main.cpp
        number.cpp
        number.h
        add_class.cpp
        add_class.h
        number_array.cpp
        number_array.h
        initiate.cpp
        initiate.h
        deleter_class.cpp
        deleter_class.h
        searcher.cpp
        searcher.h
        colors.h
        modify_class.cpp
        modify_class.h
)
target_link_libraries(txl_final_fxxku_iffiled_never mariadb)
