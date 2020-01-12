#include "level.hpp"

Level::Level(const char *name) {
    m_name = name;
}

std::string Level::getName() {
    return m_name;
}
