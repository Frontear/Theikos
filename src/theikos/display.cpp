#include "display.h"

#include <utility>
#include <iostream>

bool theikos::Display::setup = false;

theikos::Display::Display(std::string window_title, int width, int height) : title(std::move(window_title)) {
    if (setup) {
        throw std::runtime_error("Attempting to create a second theikos::Display when one already exists");
    }
    else if (width <= 0 || height <= 0) {
        throw std::runtime_error("Display dimensions must be greater than 0");
    }
    else if (title.empty()) {
        throw std::runtime_error("Display title must not be empty");
    }

    if (glfwInit() == GLFW_TRUE) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
#if __APPLE__ // https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // todo: is this necessary?
#endif
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (ptr != nullptr) {
            glfwMakeContextCurrent(ptr);

            glewExperimental = GL_TRUE;
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

theikos::Display::~Display() {
    if (!setup) {
        throw std::logic_error("Attempting to destruct a theikos::Display when setup = false, this should never happen");
    }

    glfwDestroyWindow(ptr);
    glfwTerminate();

    setup = false;
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
    if (new_title.empty()) {
        throw std::runtime_error("Display title must not be empty");
    }

    title = std::move(new_title);
    glfwSetWindowTitle(ptr, title.c_str());
}

int theikos::Display::getWidth() const {
    int width;
    glfwGetWindowSize(ptr, &width, nullptr);

    return width;
}

void theikos::Display::setWidth(int new_width) {
    if (new_width <= 0) {
        throw std::runtime_error("Display width must be greater than 0");
    }

    glfwSetWindowSize(ptr, new_width, getHeight());
}

int theikos::Display::getHeight() const {
    int height;
    glfwGetWindowSize(ptr, nullptr, &height);

    return height;
}

void theikos::Display::setHeight(int new_height) {
    if (new_height <= 0) {
        throw std::runtime_error("Display height must be greater than 0");
    }

    glfwSetWindowSize(ptr, getWidth(), new_height);
}

std::ostream &theikos::operator<<(std::ostream &os, const theikos::Display &display) {
    os << "title: " << display.title << " width: " << display.getWidth() << " height: " << display.getHeight();
    return os;
}
