cmake_minimum_required(VERSION 2.8)

project(stl_container_test)

#add_definitions(-std=c++11)
# 添加C++11支持
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

add_executable(${PROJECT_NAME} main.cpp test_array.hpp test_vector.hpp test_list.hpp test_forwardlist.hpp test_slist.hpp test_deque.hpp test_stack.hpp test_multiset.hpp test_multimap.hpp test_unordered_multiset.hpp test_unordered_multimap.hpp test_set.hpp test_map.hpp test_unordered_set.hpp test_unordered_map.hpp  pub.h)
