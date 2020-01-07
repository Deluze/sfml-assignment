cmake_minimum_required(VERSION 3.1)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "")
endif()

project(SFMLTest)
find_package(SFML REQUIRED COMPONENTS audio graphics)
add_executable(SFMLTest src/main.cpp)
target_link_libraries(SFMLTest sfml-audio sfml-graphics)