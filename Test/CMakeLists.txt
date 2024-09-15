cmake_minimum_required(VERSION 3.29.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()  

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_definitions(DEBUG)
endif()
project(func_test)
if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Catch2)
    message(STATUS "Has Catch2 submodule")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Catch2)
else()
    message(STATUS "No Catch2 submodule")
    find_package(Catch2)
    if (NOT Catch2_FOUND)
        message(STATUS "No Catch2 install, is fetching...")
        include(FetchContent)
        FetchContent_Declare(
            Catch2 
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG devel 
        )  
        FetchContent_MakeAvailable(Catch2)
    endif()
endif()



message(STATUS "dir: " ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(
    ${PROJECT_NAME} 
    Catch2::Catch2WithMain
    func
)

add_test( 
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
