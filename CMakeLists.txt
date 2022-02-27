if (WIN32)
  add_custom_target(alt-sdk
    call get-version.bat
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/version
  )
else()
  add_custom_target(alt-sdk
    ./get-version.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/version
  )
endif()