#include <iostream>
#include "theikos/display.h"

int main() {
    auto display = theikos::Display("Theikos", 640, 480);
    std::cout << display;
    
    while (display.isAlive()) {
        display.tick();
    }

    return 0;
}