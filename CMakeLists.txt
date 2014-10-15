cmake_minimum_required (VERSION 2.6)
project (IOSwitch)

#version number
set (IOSwitch_VERSION_MAJOR 0)
set (IOSwitch_VERSION_MINOR 1)

#ADD_SUBDIRECTORY(contrib)
ADD_SUBDIRECTORY(src)

include_directories("${CMAKE_SOURCE_DIR}/include")

SET(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")

