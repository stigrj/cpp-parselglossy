find_package(nlohmann_json 2.2.3 CONFIG QUIET)

if(nlohmann_json_FOUND)
  message(STATUS "Found nlohmann_json: ${nlohmann_json_INCLUDE_DIR} (found version ${nlohmann_json_VERSION})")
  add_library(nlohmann_json_external INTERFACE)  # dummy
else()
  include(ExternalProject)
  message(STATUS "Suitable nlohmann_json could not be located: downloading and building nlohmann_json instead.")
  ExternalProject_Add(nlohmann_json_external
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.5.0
    UPDATE_COMMAND ""
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
      -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
      -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
      -DJSON_BuildTests=OFF
    LOG_DOWNLOAD 1
    LOG_UPDATE 1
    LOG_CONFIGURE 1
    LOG_BUILD 1
    LOG_INSTALL 1
    )
  set(nlohmann_json_DIR ${STAGED_INSTALL_PREFIX}/lib/cmake/nlohmann_json CACHE PATH "Path to internally built nlohmann_jsonConfig.cmake" FORCE)
endif()
