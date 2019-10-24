#include "theikos/display.h"

using namespace theikos;

int main() {
    auto exit = EXIT_FAILURE;

    auto display = Display::create("Theikos", 640, 480);
    if (display != nullptr) {
        while (display->isAlive()) {
            display->tick();
        }

        exit = EXIT_SUCCESS;
    }

    delete display;

    return exit;
}