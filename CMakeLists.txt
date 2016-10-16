cmake_minimum_required(VERSION 3.0)
project(libcs)

add_library(cs idfactory.cpp keymap.cpp eventmanager.cpp componentmanager.cpp)

set(BIN_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(LIB_DIR "${CMAKE_CURRENT_BINARY_DIR}/lib")

message(STATUS "BIN_DIR: ${BIN_DIR}")
message(STATUS "LIB_DIR: ${LIB_DIR}")

# C++11 support
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# The lines above don't work for some reason...
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

# Find CppUnit
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")
find_package(CPPUNIT REQUIRED)

add_subdirectory(tests)

# Install the library
install(TARGETS cs DESTINATION ${LIB_DIR})
