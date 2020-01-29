#ifndef SFMLTEST_WAVEMANAGER_HPP
#define SFMLTEST_WAVEMANAGER_HPP

#define WAVE_COOLDOWN 60
#define ADDITIONAL_ENEMY_A_WAVE 5

#include "wave.hpp"

#include <cmath>

#include <SFML/System/Clock.hpp>

class WaveManager {
public:
    WaveManager();

    unsigned int getCurrentWaveNo();

    Wave *getCurrentWave();

    Wave *getNextWave();

    void setCurrentWaveNo(unsigned int wave);

    void forceWave();

    unsigned int getWaveCooldown();

private:
    sf::Clock m_waveClock;
    unsigned int m_waveNo;

    Wave m_currentWave;
    Wave m_nextWave;
};


#endif //SFMLTEST_WAVEMANAGER_HPP
