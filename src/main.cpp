#include <iostream>
#include "theikos/display.h"

using namespace theikos;

int main() {
    auto exit = EXIT_FAILURE;
    auto display = Display::create("Theikos", 640, 480);

    if (display != nullptr) {
        display->setTitle("Modification Test");
        display->setWidth(display->getWidth() * 2);
        display->setHeight(display->getHeight() * 2);

        std::cout << display << std::endl;

        while (display->isAlive()) {
            display->tick();
        }
    }

    Display::close(display);

    return exit;
}