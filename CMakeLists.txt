cmake_minimum_required(VERSION 3.8)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "")
endif()

project(SFMLTest)

find_package(SFML REQUIRED COMPONENTS graphics window)

add_executable(SFMLTest src/main.cpp)

set_property(TARGET SFMLTest PROPERTY CXX_STANDARD 17)

add_subdirectory(src)

target_link_libraries(SFMLTest sfml-graphics sfml-window)