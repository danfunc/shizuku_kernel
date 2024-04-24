
set(PICO_SDK_FETCH_FROM_GIT on)
file(DOWNLOAD https://raw.githubusercontent.com/raspberrypi/pico-sdk/master/external/pico_sdk_import.cmake pico_sdk_import.cmake)
include(${CMAKE_CURRENT_BINARY_DIR}/pico_sdk_import.cmake)
