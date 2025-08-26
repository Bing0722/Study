cmake_minimum_required(VERSION 3.30)

project(Log VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(logger
  AsyncLogging.cc
  CountDownLatch.cc
  FileUtil.cc
  LogFile.cc
  LogStream.cc
  Logging.cc
  Thread.cc
)

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME} logger)
