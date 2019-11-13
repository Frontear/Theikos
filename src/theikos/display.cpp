#include "display.h"

#include <utility>
#include <iostream>

bool theikos::Display::setup = false;

theikos::Display::Display(std::string window_title, int window_width, int window_height)
    : title(std::move(window_title)), width(window_width), height(window_height) {
    if (setup) {
        throw std::runtime_error("Attempting to create a second theikos::Display when one already exists");
    }
    else {
        if (glfwInit() == GLFW_TRUE) {
            ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
            if (ptr != nullptr) {
                glfwMakeContextCurrent(ptr);

                //glewExperimental = GL_TRUE;
                if (glewInit() == GLEW_OK) {
                    glfwSwapInterval(1);

                    setup = true;
                }
            }
        }

        if (!setup) {
            throw std::runtime_error("Failed to create theikos::Display, could not meet required OpenGL setup");
        }
    }
}

theikos::Display::~Display() {
    if (!setup) {
        throw std::logic_error("Attempting to destruct a theikos::Display when setup = false, this should never happen");
    }
    else {
        glfwDestroyWindow(ptr);
        glfwTerminate();

        setup = false;
    }
}

bool theikos::Display::isAlive() {
    return glfwWindowShouldClose(ptr) == GLFW_FALSE;
}

void theikos::Display::tick() {
    glfwSwapBuffers(ptr);
    glfwPollEvents();
}

std::string theikos::Display::getTitle() {
    return title;
}

void theikos::Display::setTitle(std::string new_title) {
    title = std::move(new_title);
    glfwSetWindowTitle(ptr, title.c_str());
}

int theikos::Display::getWidth() {
    return width;
}

void theikos::Display::setWidth(int new_width) {
    width = new_width;
    glfwSetWindowSize(ptr, width, height);
}

int theikos::Display::getHeight() {
    return height;
}

void theikos::Display::setHeight(int new_height) {
    height = new_height;
    glfwSetWindowSize(ptr, width, height);
}

std::ostream &theikos::operator<<(std::ostream &os, const theikos::Display &display) {
    os << "title: " << display.title << " width: " << display.width << " height: " << display.height;
    return os;
}
