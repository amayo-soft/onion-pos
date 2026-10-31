cmake_minimum_required(VERSION 3.22)
project(onion-pos VERSION 0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON) # resource file e.g .qrc

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")

if(CLANG_TIDY_EXE)
  set(CLANG_TIDY_WRAPPER "${CMAKE_SOURCE_DIR}/utils/clang-tidy-wrapper.py")

  set(CMAKE_CXX_CLANG_TIDY
    "python3;${CLANG_TIDY_WRAPPER};${CLANG_TIDY_EXE};-extra-arg=-std=c++20;-extra-arg=-Wno-unknown-warning-option;-extra-arg=-Wno-ignored-optimization-argument"
  )
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/gui/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.hpp")

add_executable(onion ${SOURCES} ${HEADERS} res.qrc)

target_include_directories(onion PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(onion PRIVATE
                      Qt6::Core
                      Qt6::Gui
                      Qt6::Widgets)
