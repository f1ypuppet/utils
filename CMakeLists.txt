cmake_minimum_required(VERSION 3.20)

project(
    utils
    LANGUAGES C CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/detection")
include(cpuid)

set(UTILS_INCLUDE_ROOT_DIR "${CMAKE_SOURCE_DIR}/include/utils")
configure_file(
    "${CMAKE_SOURCE_DIR}/config.h.in"
    "${UTILS_INCLUDE_ROOT_DIR}/base/config.h")