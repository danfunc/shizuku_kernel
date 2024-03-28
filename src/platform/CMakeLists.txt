if(DEFINED ENV{SHIZUKU_PLATFORM} AND NOT SHIZUKU_PLATFORM)
  set(SHIZUKU_PLATFORM $ENV{SHIZUKU_PLATFORM})
endif()

if(DEFINED SHIZUKU_PLATFORM)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SHIZUKU_PLATFORM}/CMakeLists.txt)
    add_subdirectory(${SHIZUKU_PLATFORM})
  else()
    message(
      SEND_ERROR "${SHIZUKU_PLATFORM} not supported please check this directory"
    )
  endif()
endif()