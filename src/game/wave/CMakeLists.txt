set(PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(SFMLTest PRIVATE
        ${PATH}/waveManager.cpp
        ${PATH}/waveManager.hpp
        ${PATH}/wave.hpp
        ${PATH}/wave.cpp
)