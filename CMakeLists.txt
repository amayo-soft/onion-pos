cmake_minimum_required(VERSION 3.22)
project(
  onion-pos
  VERSION 1.0
  DESCRIPTION "Point of Sale Written in C++ and Qt6"
  HOMEPAGE_URL "https://github.com/amayo-soft"
  LANGUAGES CXX C
)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets Gui Core REQUIRED)

qt_standard_project_setup()

# .ui files paths, make the life better; thanks cmake
set(CMAKE_AUTOUIC_SEARCH_PATHS
      "${CMAKE_CURRENT_SOURCE_DIR}/onion-qt/"
      "${CMAKE_CURRENT_SOURCE_DIR}/onion-qt/sale/"
)

# All Resource Files Goes Here
file(GLOB_RECURSE RESOURCE CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/onion-qt/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/onion-qt/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/onion-qt/sale/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/onion-qt/sale/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/*.hpp"
)
add_executable(${PROJECT_NAME}
            ${RESOURCE}
            res.qrc
)

# Optimze Compilation Time
target_precompile_headers(${PROJECT_NAME} INTERFACE
                          QtWidgets.h QtCore.h QtGui.h
)

target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Core Qt6::Gui)
