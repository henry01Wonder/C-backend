# 設定包括的頭文件目錄
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# 動態添加 src 資料夾下的所有 .cpp 文件
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 創建靜態庫或共享庫（根據需求）
add_library(depend_libry ${SOURCES})
