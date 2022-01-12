cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(knn_classification)

set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(matplotplusplus)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(main.out ${SRC_FILES})
target_link_libraries(main.out PUBLIC matplot)

target_include_directories(main.out PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/matplotplusplus")

target_include_directories(main.out PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
