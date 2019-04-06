add_test(
  NAME
    integration-default
  COMMAND
    ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/test
    --binary=${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}
    --work-dir=${CMAKE_CURRENT_BINARY_DIR}
    --verbose
  WORKING_DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}
  )
