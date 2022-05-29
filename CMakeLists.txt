if(NOT SDK_PROJECT_NAME)
    set(SDK_PROJECT_NAME alt-sdk)
endif()

if (CMAKE_HOST_WIN32)
  add_custom_target(${SDK_PROJECT_NAME}
    call get-version.bat
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/version
  )
else()
  add_custom_target(${SDK_PROJECT_NAME}
    bash get-version.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/version
  )
endif()
