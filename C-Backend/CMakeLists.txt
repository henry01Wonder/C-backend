# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed.
    You should create a separate directory for build files."  )
endif()

# 設定 C++ 標準
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 專案名稱
project(backend)

# 包含子目錄
add_subdirectory(src)
add_subdirectory(app)

