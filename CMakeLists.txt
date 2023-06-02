cmake_minimum_required(VERSION 3.9.1)
project(CMakeHello)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

enable_language(Rust)
include(CMakeCargo)

include_directories("include")
add_subdirectory(rust-lib)

execute_process (
    COMMAND bash -c "./generate_cpp_headers.sh"
    OUTPUT_VARIABLE outVar
)

# file(WRITE "datestamp" "${outVar}")

# Disable in-source builds to prevent source tree corruption.
# if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  # message(FATAL_ERROR "
# FATAL: In-source builds are not allowed.
       # You should create a separate directory for build files.
# ")
# endif()

if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
	  add_definitions(-DCMAKE_MACRO_EXAMPLE="Unix System")
elseif(WIN32)
    message("This is a Windows System")
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    message("This is a Windows System")
endif()

add_executable(cmake_hello main.cpp)


if(WIN32)
  target_link_libraries(cmake_hello rust-lib ws2_32 userenv)
else()
  target_link_libraries(cmake_hello rust-lib dl pthread)
endif()
