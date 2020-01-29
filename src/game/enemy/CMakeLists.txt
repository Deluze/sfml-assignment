set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/enemy.cpp
        ${PATH}/enemy.hpp
        ${PATH}/enemyManager.hpp
        ${PATH}/enemyManager.cpp
        ${PATH}/enemyType.hpp
        ${PATH}/enemyDirection.hpp
)
