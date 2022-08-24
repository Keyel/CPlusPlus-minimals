# CMakeList.txt : CMake project for smart_pointers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (smart_pointers "smart_pointers.cpp" "smart_pointers.h" "shared_pointer.h" "unique_pointer.h" "unique_pointer.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET smart_pointers PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
