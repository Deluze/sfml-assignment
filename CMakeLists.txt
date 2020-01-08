cmake_minimum_required(VERSION 3.1)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "")
endif()

project(SFMLTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML REQUIRED COMPONENTS graphics)

add_executable(SFMLTest src/main.cpp)

add_subdirectory(src)

target_link_libraries(SFMLTest sfml-graphics)