cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

project(main VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API TRUE)

file(GLOB SOURCES "*.cc")

add_library(math)

target_sources(math
  PRIVATE
    math.cppm # 必须使用 CMake 识别的模块接口扩展名
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME})

target_compile_options(math PRIVATE -fmodules-ts)
target_compile_options(${PROJECT_NAME} PRIVATE -fmodules-ts)
