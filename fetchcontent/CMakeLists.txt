cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(cpp-parselglossy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${PROJECT_SOURCE_DIR}/external/upstream/fetch_nlohmann_json.cmake)

add_subdirectory(src)
