# 設定包括的頭文件目錄
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# 添加主執行文件
add_executable(main main.cpp)

# 連結到庫
target_link_libraries(main PRIVATE depend_libry)
