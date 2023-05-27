cmake_minimum_required(VERSION 3.20)
project(
  cocktail
  LANGUAGES C CXX
)

message(STATUS "Project: '${PROJECT_NAME}'")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Debug")

add_compile_options(-fno-rtti)

# CMake helpers:
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

include(CTest)

include_directories(include)

# Create the cocktail C++ library
set(SRCS)

set(STATIC_LIB_NAME ${PROJECT_NAME})

# apt install llvm-15-dev
set(LLVM_DIR /usr/lib/llvm-15/lib/cmake/llvm)
# manually install
# set(LLVM_DIR /usr/local/lib/cmake/llvm)

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

file(GLOB_RECURSE LIB_PATH
    ./lib/Lexer/*.cc
  )
list(APPEND SRCS ${LIB_PATH})

add_library(${STATIC_LIB_NAME} STATIC ${SRCS})
target_link_libraries(${STATIC_LIB_NAME}
  LLVMSupport
  LLVMOption
)

add_subdirectory(unittests #[[EXCLUDE_FROM_ALL]])
