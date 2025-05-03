cmake_minimum_required(VERSION 3.10)
project(Easy-ASG)

# 设置依赖路径（Windows示例）
set(ZLIB_ROOT "C:/vcpkg/installed/x64-windows")
set(PNG_ROOT "C:/vcpkg/installed/x64-windows")

# 查找依赖
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)

# 包含 libharu 子目录
add_subdirectory(thirdparty/libharu)

# 包含路径
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${ZLIB_INCLUDE_DIRS}
    ${PNG_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libharu/include
)

# 添加可执行文件
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/answersheetgenerator.cpp
)

# 链接库
target_link_libraries(${PROJECT_NAME}
    libharu
    ${ZLIB_LIBRARIES}
    ${PNG_LIBRARIES}
)
