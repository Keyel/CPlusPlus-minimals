# CMakeList.txt : CMake project for Memoize, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Memoize")

# Add source to this project's executable.
add_executable (Memoize "Memoize.cpp" "Memoize.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Memoize PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
