cmake_minimum_required(VERSION 3.16)
project(Totoro)

set(CMAKE_CXX_STANDARD 14)


aux_source_directory(src SRC_SUB)
aux_source_directory(include SRC_CUR)


add_executable(Totoro ${SRC_SUB} ${SRC_CUR})

include_directories(include)
