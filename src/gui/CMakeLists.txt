set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/UIElement.hpp
        ${PATH}/UIElement.cpp
        ${PATH}/button.cpp
        ${PATH}/button.hpp
)

add_subdirectory(exception)
add_subdirectory(game)