execute_process(
  COMMAND
    cmake -E create_symlink
    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_DATADIR}/template.yml" # Old name
    "${CMAKE_CURRENT_BINARY_DIR}/template.yml" # New name
  )

file(
  COPY
    pi.inp
  DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}
  )

add_test(
  NAME
    integration-default
  COMMAND
    ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/test
    --binary=${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
    --work-dir=${CMAKE_CURRENT_BINARY_DIR}
    --verbose
  WORKING_DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}
  )
