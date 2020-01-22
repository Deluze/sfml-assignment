set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/gameObject.cpp
        ${PATH}/gameObject.hpp
        ${PATH}/grid.hpp
        ${PATH}/grid.cpp
        ${PATH}/game.cpp
        ${PATH}/game.hpp
)

add_subdirectory(tile)
add_subdirectory(tower)
add_subdirectory(enemy)
add_subdirectory(wave)
