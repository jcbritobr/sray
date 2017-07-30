cmake_minimum_required(VERSION 2.8)

project(sray)
add_compile_options("-std=c++14")
file(GLOB_RECURSE source_list "*.hpp" "*.cpp")
add_executable(${PROJECT_NAME} ${source_list})
