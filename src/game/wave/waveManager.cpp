#include "waveManager.hpp"

WaveManager::WaveManager() : m_waveNo(0), m_nextWave(ADDITIONAL_ENEMY_A_WAVE), m_currentWave(0, 0) {

}

unsigned int WaveManager::getCurrentWaveNo() {
    return m_waveNo;
}

void WaveManager::setCurrentWaveNo(unsigned int wave) {
    m_waveNo = wave;
    m_waveClock.restart();

    m_nextWave = Wave{m_waveNo * ADDITIONAL_ENEMY_A_WAVE + ADDITIONAL_ENEMY_A_WAVE};
}

unsigned int WaveManager::getWaveCooldown() {
    return std::floor(std::abs(WAVE_COOLDOWN - m_waveClock.getElapsedTime().asSeconds()));
}

void WaveManager::forceWave() {
    setCurrentWaveNo(m_waveNo + 1);
}

Wave *WaveManager::getNextWave() {
    return &m_nextWave;
}

Wave *WaveManager::getCurrentWave() {
    return &m_currentWave;
}
