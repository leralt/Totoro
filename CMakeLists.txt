cmake_minimum_required(VERSION 3.16)
project(Totoro)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

aux_source_directory(src SRC_SUB)
aux_source_directory(include INCLUDE_SUB)


add_executable(Totoro ${SRC_SUB} ${INCLUDE_SUB} src/wrap.cpp)


