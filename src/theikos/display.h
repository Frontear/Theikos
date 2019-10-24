#ifndef THEIKOS_SRC_THEIKOS_DISPLAY_H_
#define THEIKOS_SRC_THEIKOS_DISPLAY_H_

#include <string>
#include <utility>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace theikos {
    class Display {
    private:
        std::string title;
        int width{}, height{};
        GLFWwindow* window = nullptr;

    public:
        Display() = default;

    public:
        static Display* create(const std::string& title, int width, int height) {
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
    };
}

#endif //THEIKOS_SRC_THEIKOS_DISPLAY_H_
