#ifndef SFMLTEST_LEVEL_HPP
#define SFMLTEST_LEVEL_HPP

#include <string>

class Level {
public:
    explicit Level(const char* name);

    std::string getName();
private:
    std::string m_name;
};


#endif //SFMLTEST_LEVEL_HPP
