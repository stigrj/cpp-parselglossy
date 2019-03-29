cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(cpp-parselglossy_core
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

find_package(nlohmann_json CONFIG REQUIRED)
get_target_property(
  _loc
  nlohmann_json::nlohmann_json
  INTERFACE_INCLUDE_DIRECTORIES
  )
message(STATUS "Found nlohmann_json: ${_loc} (found version ${nlohmann_json_VERSION})")

add_executable(pi.x pi.cpp)

target_link_libraries(pi.x
  PRIVATE
    nlohmann_json::nlohmann_json
  )

# RPATH fixing
file(RELATIVE_PATH _rel ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR} ${CMAKE_INSTALL_PREFIX})
if(APPLE)
  set(_rpath "@loader_path/${_rel}")
else()
  set(_rpath "\$ORIGIN/${_rel}")
endif()
file(TO_NATIVE_PATH "${_rpath}/${CMAKE_INSTALL_LIBDIR}" Pi_RPATH)

set_target_properties(pi.x
  PROPERTIES
    MACOSX_RPATH ON
    SKIP_BUILD_RPATH OFF
    BUILD_WITH_INSTALL_RPATH OFF
    INSTALL_RPATH "${Pi_RPATH}"
    INSTALL_RPATH_USE_LINK_PATH ON
  )

install(
  TARGETS
    pi.x
  RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT bin
  )

