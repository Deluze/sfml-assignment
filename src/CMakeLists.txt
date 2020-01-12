set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/engine.cpp
        ${PATH}/engine.hpp
        ${PATH}/sceneManager.cpp
        ${PATH}/sceneManager.hpp
        ${PATH}/eventManager.cpp
        ${PATH}/eventManager.hpp
        ${PATH}/eventBag.hpp
        ${PATH}/eventBag.cpp
)

add_subdirectory(gui)
add_subdirectory(scene)
add_subdirectory(game)