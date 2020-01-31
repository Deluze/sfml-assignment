#include "engine.hpp"

int main() {
    Engine engine{"My Engine :)"};

    engine.initialize();
    engine.start();

    return 0;
}