#include <iostream>
#include "theikos/display.h"

using namespace theikos;

int main() {
    auto exit = EXIT_FAILURE;

    auto display = Display::create("Theikos", 640, 480);
    if (display != nullptr) {
        display->setTitle("Theikos - Modified");
        std::cout << display << std::endl;
        while (display->isAlive()) {
            display->tick();
        }

        exit = EXIT_SUCCESS;
    }

    delete display;

    return exit;
}