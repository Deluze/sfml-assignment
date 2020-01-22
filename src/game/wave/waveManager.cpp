#include "waveManager.hpp"

unsigned int WaveManager::getCurrentWave() {
    return m_waveNo;
}

void WaveManager::setCurrentWave(unsigned int wave) {
    m_waveNo = wave;

    m_waveClock.restart();
}

unsigned int WaveManager::getWaveCooldown() {
    return std::floor(std::abs(WAVE_COOLDOWN - m_waveClock.getElapsedTime().asSeconds()));
}

void WaveManager::forceWave() {
    m_waveNo++;

    m_waveClock.restart();
}
