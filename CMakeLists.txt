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

# This will always be there.. for safety I guess
add_custom_command(
        TARGET SFMLTest
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/asset
        $<TARGET_FILE_DIR:SFMLTest>/asset
)

if(WIN32)
    #Only Debug build now
    #therefore..
    add_custom_command(
            TARGET SFMLTest
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/asset
            $<TARGET_FILE_DIR:SFMLTest>/Debug/asset
    )
endif()


target_link_libraries(SFMLTest sfml-graphics sfml-window sfml-system)