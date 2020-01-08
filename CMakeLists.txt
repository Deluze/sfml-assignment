cmake_minimum_required(VERSION 3.8)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "")
endif()

project(SFMLTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED COMPONENTS graphics window system)

add_executable(SFMLTest src/main.cpp)

add_subdirectory(src)

file(COPY asset DESTINATION ./)

target_link_libraries(SFMLTest sfml-graphics sfml-window sfml-system)