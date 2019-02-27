cmake_minimum_required(VERSION 2.4)

project(ZiaModuleAPISpec)
set(CMAKE_CXX_STANDARD 11)

add_library(ZiaModuleAPISpec INTERFACE)
target_include_directories(ZiaModuleAPISpec INTERFACE include/)