cmake_minimum_required(VERSION 3.5...3.29)
project(test)

add_subdirectory(pybind11)

find_package(PythonLibs REQUIRED)

add_executable(test main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

target_include_directories(test PRIVATE 
    ${PYTHON_INCLUDE_DIRS} 
    ${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include
)

target_link_libraries(test PRIVATE pybind11::embed ${PYTHON_LIBRARIES})