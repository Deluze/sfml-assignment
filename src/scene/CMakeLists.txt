set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/scene.hpp
        ${PATH}/scene.cpp
        ${PATH}/mainMenuScene.cpp
        ${PATH}/mainMenuScene.hpp
        ${PATH}/UIManager.hpp
        ${PATH}/UIManager.cpp
        ${PATH}/levelSelectorScene.hpp
        ${PATH}/levelSelectorScene.cpp
)
add_subdirectory(exception)