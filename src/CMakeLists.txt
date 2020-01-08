set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/game.cpp
        ${PATH}/game.hpp
        ${PATH}/loopable.hpp
)

add_subdirectory(gui)
add_subdirectory(scene)