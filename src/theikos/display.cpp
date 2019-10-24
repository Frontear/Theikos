#include "display.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"

theikos::Display::Display(std::string title, int width, int height)
    : title(std::move(title)), width(width), height(height) {}

theikos::Display::~Display() {
    glfwDestroyWindow(window_ptr);
    glfwTerminate();
}

theikos::Display *theikos::Display::create(const std::string &title, int width, int height) {
    auto display = new Display(title, width, height);

    if (glfwInit() == GLFW_TRUE) {
        display->window_ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (display->window_ptr != nullptr) {
            glfwMakeContextCurrent(display->window_ptr);
            if (glewInit() == GLEW_OK) {
                glfwSwapInterval(1);
                return display;
            }
        }
    }

    return nullptr;
}

void theikos::Display::close(const theikos::Display *display) {
    delete display;
}

const std::string &theikos::Display::getTitle() {
    return title;
}

void theikos::Display::setTitle(const std::string &title) {
    Display::title = title;
    glfwSetWindowTitle(window_ptr, title.c_str());
}

int theikos::Display::getWidth() {
    return width;
}

void theikos::Display::setWidth(int width) {
    Display::width = width;
    glfwSetWindowSize(window_ptr, width, height);
}

int theikos::Display::getHeight() {
    return height;
}

void theikos::Display::setHeight(int height) {
    Display::height = height;
    glfwSetWindowSize(window_ptr, width, height);
}

bool theikos::Display::isAlive() {
    return glfwWindowShouldClose(window_ptr) == GLFW_FALSE;
}

void theikos::Display::tick() {
    glfwSwapBuffers(window_ptr);
    glfwPollEvents();
}

std::ostream &theikos::operator<<(std::ostream &os, const theikos::Display *display) {
    os << "title: " << display->title << " width: " << display->width << " height: " << display->height;
    return os;
}

#pragma clang diagnostic pop