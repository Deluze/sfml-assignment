set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/scene.hpp
        ${PATH}/mainMenuScene.cpp
        ${PATH}/mainMenuScene.hpp
)

add_subdirectory(exception)