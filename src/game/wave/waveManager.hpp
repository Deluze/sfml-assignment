#ifndef SFMLTEST_WAVEMANAGER_HPP
#define SFMLTEST_WAVEMANAGER_HPP

#define WAVE_COOLDOWN 60

#include <cmath>

#include <SFML/System/Clock.hpp>

class WaveManager {
public:
    unsigned int getCurrentWave();
    void setCurrentWave(unsigned int wave);
    void forceWave();
    unsigned int getWaveCooldown();
private:
    sf::Clock m_waveClock;
    unsigned int m_waveNo;
};


#endif //SFMLTEST_WAVEMANAGER_HPP
