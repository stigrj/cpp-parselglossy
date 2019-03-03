add_executable(example example.cpp)

target_link_libraries(example
  PRIVATE
    nlohmann_json::nlohmann_json
  )
