set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/UIElement.hpp
        ${PATH}/UIElement.cpp
)

add_subdirectory(exception)