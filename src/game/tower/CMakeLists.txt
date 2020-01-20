set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/tower.cpp
        ${PATH}/tower.hpp
        ${PATH}/towerType.hpp
        ${PATH}/towerManager.hpp
        ${PATH}/towerManager.cpp
)