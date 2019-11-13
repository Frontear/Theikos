#include <iostream>
#include "theikos/display.h"

int main() {
    auto display = theikos::Display("Theikos", 640, 480);
    std::cout << display;

    /*
    // -- IMMEDIATE MODE
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, display.getWidth(), display.getHeight(), 0, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    // -- IMMEDIATE MODE
    */

    auto width = 400, height = 200, x = (display.getWidth() - width) / 2, y = (display.getHeight() - height) / 2;
    do {
        glClear(GL_COLOR_BUFFER_BIT);
        /*
        // -- IMMEDIATE MODE
        glColor3f(0.5f, 0.5f, 1.0f);
        glBegin(GL_QUADS);
        {
            glVertex2f(x, y);
            glVertex2f(x + width, y);
            glVertex2f(x + width, y + height);
            glVertex2f(x, y + height);
        }
        glEnd();
        // -- IMMEDIATE MODE
        */

        display.tick();
    }
    while (display.isAlive());

    return 0;
}