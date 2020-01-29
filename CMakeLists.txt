cmake_minimum_required(VERSION 3.8)

if (DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "")
endif ()

project(SFMLTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED COMPONENTS graphics window system)

add_executable(SFMLTest src/main.cpp)

add_subdirectory(src)

file(COPY asset DESTINATION ./)

if (WIN32)
    # We have to copy it to 2 locations. Since the directory context of starting an executable through VS fiddles around with the directory context.
    add_custom_command(
            TARGET SFMLTest
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/asset
            $<TARGET_FILE_DIR:SFMLTest>/${CMAKE_BUILD_TYPE}/asset
    )
endif ()


target_link_libraries(SFMLTest sfml-graphics sfml-window sfml-system)