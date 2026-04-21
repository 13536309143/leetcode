cmake_minimum_required(VERSION 3.10)
project(1722)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(236 src/236.cpp)
# file(GLOB SOURCES "*.cpp")
# foreach(source ${SOURCES})
#     get_filename_component(target_name ${source} NAME_WE)
#     add_executable(${target_name} ${source})
# endforeach()
