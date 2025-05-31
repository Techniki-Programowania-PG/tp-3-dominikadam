cmake_minimum_required(VERSION 3.14)
project(scikit_build_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Python3_EXECUTABLE "C:/Users/adam/miniconda3/python.exe")
set(Python3_LIBRARY "C:/Users/adam/miniconda3/libs/python313.lib")
set(Python3_INCLUDE_DIR "C:/Users/adam/miniconda3/include")
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.11.1
)
FetchContent_MakeAvailable(pybind11)

add_subdirectory(external/matplotplusplus)

add_library(signal_module
    cpp/signals.cpp
    cpp/filter.cpp
)
target_include_directories(signal_module PUBLIC cpp)
target_link_libraries(signal_module PRIVATE matplot)
set_target_properties(signal_module PROPERTIES POSITION_INDEPENDENT_CODE ON)

pybind11_add_module(scikit_build_example
    src/scikit_build_example/bindings.cpp
)
target_include_directories(scikit_build_example
    PRIVATE
    cpp
    external/matplotplusplus/source
)
target_link_libraries(scikit_build_example
    PRIVATE
    signal_module
    pybind11::pybind11
)

if (MSVC)
    set_target_properties(matplot PROPERTIES COMPILE_OPTIONS "/WX-")
endif()

set_target_properties(scikit_build_example PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src/scikit_build_example
)
