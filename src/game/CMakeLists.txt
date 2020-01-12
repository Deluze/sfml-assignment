set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/level.cpp
        ${PATH}/level.hpp
        ${PATH}/gameObject.cpp
        ${PATH}/gameObject.hpp
        ${PATH}/grid.hpp
        ${PATH}/grid.cpp
)

add_subdirectory(tile)
add_subdirectory(tower)
