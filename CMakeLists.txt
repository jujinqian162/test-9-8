# 这个示例中库名字作为 func
# 其本地存放头文件的文件夹（include）也为 func （这个文件夹的内容会被安装到install）
# 项目结构：
# .
# ├── CMakeLists.txt    
# ├── func    存放header
# └── src               存放.c,.cpp文件
# 

cmake_minimum_required(VERSION 3.29.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()  

project(func)

file(GLOB LIB_SRC src/*.cpp include/func/*.h)

add_library(func 
                            STATIC 
#                           SHARED
                            ${LIB_SRC}
)
add_library(func::func ALIAS func)
set_target_properties(func 
    PROPERTIES 
    LANGUAGE CXX
)
include(CMakePackageConfigHelpers)
# set install path:
#SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
target_include_directories(func PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/func>
    $<INSTALL_INTERFACE:include>
)
# set_target_properties(func PROPERTIES PUBLIC_HEADER "func/lib2.h")
install(TARGETS func
    EXPORT func-targets
    PUBLIC_HEADER DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
#use this if you want to install func directory to installpath/include but not single header
install(DIRECTORY  ${CMAKE_SOURCE_DIR}/include/func DESTINATION include)
install(EXPORT func-targets
    NAMESPACE func::
    FILE func-config.cmake
    DESTINATION lib/cmake/func
)

include_directories(${CMAKE_SOURCE_DIR}/include)
enable_testing()
add_subdirectory(Test)
