set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/gameObject.cpp
        ${PATH}/gameObject.hpp
        ${PATH}/grid.hpp
        ${PATH}/grid.cpp
        ${PATH}/levelManager.cpp
        ${PATH}/levelManager.hpp
)

add_subdirectory(tile)
add_subdirectory(tower)
