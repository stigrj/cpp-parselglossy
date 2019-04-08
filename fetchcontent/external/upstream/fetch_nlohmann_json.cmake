find_package(nlohmann_json 3.5.0 CONFIG QUIET)

if(TARGET nlohmann_json::nlohmann_json)
  get_target_property(
    _loc
    nlohmann_json::nlohmann_json
    INTERFACE_INCLUDE_DIRECTORIES
    )
  message(STATUS "Found nlohmann_json: ${_loc} (found version ${nlohmann_json_VERSION})")
else()
  message(STATUS "Suitable nlohmann_json could not be located. Fetching and building!")
  include(FetchContent)

  FetchContent_Populate(nlhomann_json_sources
    QUIET
    GIT_REPOSITORY
      https://github.com/nlohmann/json
    GIT_TAG
      v3.5.0
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
      -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
      -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
      -DBUILD_TESTING=OFF
      -DJSON_BuildTests=OFF
    CMAKE_CACHE_ARGS
      -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
    )

  set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
  set(JSON_BuildTests OFF CACHE BOOL "" FORCE)

  add_subdirectory(
    ${nlhomann_json_sources_SOURCE_DIR}
    ${nlohmann_json_sources_BINARY_DIR}
    )
endif()
