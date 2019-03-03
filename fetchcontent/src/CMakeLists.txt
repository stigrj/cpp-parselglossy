cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cpp-parselglossy_core LANGUAGES CXX)

find_package(nlohmann_json CONFIG REQUIRED)
get_target_property(
  _loc
  nlohmann_json::nlohmann_json
  INTERFACE_INCLUDE_DIRECTORIES
  )
message(STATUS "Found nlohmann_json: ${_loc} (found version ${nlohmann_json_VERSION})")

add_executable(example example.cpp)

target_link_libraries(example
  PRIVATE
    nlohmann_json::nlohmann_json
  )
