cmake_minimum_required(VERSION 3.5)


# project name
project(cpp_learning)


# compiler selection
SET(CMAKE_C_COMPILER "/usr/bin/gcc" CACHE PATH "gcc compiler")
SET(CMAKE_CXX_COMPILER "/usr/bin/g++" CACHE PATH "g++ compiler")

# build type
# Debug
# Release
# RelWithDebugInfo
SET(CMAKE_BUILD_TYPE Debug)


# set up cxx compiler flags.
# NDEBUG -> disable runtime assert & trace.
set(CMAKE_CXX_FLAGS                "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")


# checking compiler feature support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if (COMPILER_SUPPORTS_CXX11)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif (COMPILER_SUPPORTS_CXX0X)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=cxx0x")
else()
  message(FATAL_ERROR "Compiler ${CMAKE_CXX_COMPILER} has no c++11 & cxx0x support")
endif()

message(STATUS "Current build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Current compiling flags: ${CMAKE_CXX_FLAGS}")

message(STATUS "CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
  message(STATUS ${CMAKE_SYSTEM_PROCESSOR} " processor detected. Define -mfpu=neon")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=neon")
elseif (${CMAKE_SYSTEM_PROCESSOR} MATCHES "^aarch64")
  message(STATUS ${CMAKE_SYSTEM_PROCESSOR} " processor detected. NEON automatically used")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=neon")
else()
  message(STATUS "Assuming SSE instructions available.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mssse3")
endif()


# finding dependency
find_package(GTest REQUIRED)


# add sub directory
add_subdirectory(algorithm)
