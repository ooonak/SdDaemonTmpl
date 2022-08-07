cmake_minimum_required(VERSION 3.16)

project(MyProject VERSION 0.0.1 LANGUAGES CXX)

file(WRITE ${PROJECT_BINARY_DIR}/myprojectconfig.hpp.in "
#pragma once

#define MYPROJECT_VERSION_MAJOR @MyProject_VERSION_MAJOR@
#define MYPROJECT_VERSION_MINOR @MyProject_VERSION_MINOR@
#define MYPROJECT_VERSION_PATCH @MyProject_VERSION_PATCH@
")

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

# Find Boost headers and some static (release only) libraries
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost REQUIRED COMPONENTS system)

find_package(spdlog REQUIRED)

add_library(myproject
    include/myproject/myproject.hpp
    myproject.cpp
)

target_compile_features(myproject PUBLIC cxx_std_20)

target_include_directories(myproject
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
    ${spdlog_SOURCE_DIR}/include
    ${OPENSSL_INCLUDE_DIR}
    #${Boost_INCLUDE_DIRS}
)

target_link_libraries(myproject
    PRIVATE
    spdlog::spdlog
    Threads::Threads
    ${OPENSSL_LIBRARIES}
    #${Boost_LIBRARIES}
    Boost::Boost
)

add_library(myproject::myproject ALIAS myproject)

configure_file("${PROJECT_BINARY_DIR}/myprojectconfig.hpp.in" myprojectconfig.hpp)

install(TARGETS myproject
        EXPORT ${CMAKE_PROJECT_NAME}Targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/myproject
        DESTINATION include
        COMPONENT Devel
)
