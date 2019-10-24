#ifndef THEIKOS_SRC_THEIKOS_DISPLAY_H_
#define THEIKOS_SRC_THEIKOS_DISPLAY_H_

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ostream>

namespace theikos {
    class Display {
    private:
        std::string title;
        int width{}, height{};
        GLFWwindow *window = nullptr;

        Display() = default;

    public:
        static Display *create(const std::string &title, int width, int height) {
            auto display = new Display();
            display->title = title;
            display->width = width;
            display->height = height;

            if (glfwInit() == GLFW_TRUE) {
                display->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
                if (display->window != nullptr) {
                    glfwMakeContextCurrent(display->window);
                    if (glewInit() == GLEW_OK) {
                        glfwSwapInterval(1);
                        return display;
                    }
                }
            }

            return nullptr;
        }

        bool isAlive() {
            return glfwWindowShouldClose(window) == GLFW_FALSE;
        }

        void tick() {
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        virtual ~Display() {
            glfwDestroyWindow(window);
            glfwTerminate();
        }

        void setTitle(const std::string &t) {
            this->title = t;
            glfwSetWindowTitle(window, t.c_str());
        }

        friend std::ostream &operator<<(std::ostream &os, const Display *display);
    };

    std::ostream &operator<<(std::ostream &os, const Display *display) {
        os << "title: \"" << display->title << "\", width: " << display->width << ", height: " << display->height;
        return os;
    }
}

#endif //THEIKOS_SRC_THEIKOS_DISPLAY_H_