#include "main.h"

int main() {
    auto exit = EXIT_FAILURE;

    if (glfwInit() == GLFW_TRUE) {
        auto window = glfwCreateWindow(640, 480, "Theikos", nullptr, nullptr);
        if (window != nullptr) {
            glfwMakeContextCurrent(window);
            if (glewInit() == GLEW_OK) {
                glfwSwapInterval(1);
                while (glfwWindowShouldClose(window) == GLFW_FALSE) {
                    // rendering stuff

                    glfwSwapBuffers(window);
                    glfwPollEvents();
                }

                exit = EXIT_SUCCESS;
            }

            glfwDestroyWindow(window);
        }
    }

    glfwTerminate();

    return exit;
}