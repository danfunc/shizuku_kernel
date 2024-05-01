
set(PICO_SDK_FETCH_FROM_GIT on)
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/pico_sdk_import.cmake)
file(DOWNLOAD https://raw.githubusercontent.com/raspberrypi/pico-sdk/master/external/pico_sdk_import.cmake pico_sdk_import.cmake)
endif()
include(${CMAKE_CURRENT_BINARY_DIR}/pico_sdk_import.cmake)
