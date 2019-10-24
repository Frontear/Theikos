#ifndef THEIKOS_SRC_THEIKOS_DISPLAY_H_
#define THEIKOS_SRC_THEIKOS_DISPLAY_H_

#include <string>
#include <utility>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ostream>

namespace theikos {
    class Display {
    private:
        std::string title = "";
        int width = 0, height = 0;
        GLFWwindow *window_ptr = nullptr;

        Display(std::string title, int width, int height);
        ~Display();

    public:
        static Display *create(const std::string &title, int width, int height);
        static void close(const Display *display);

        bool isAlive();
        void tick();

        const std::string &getTitle();
        void setTitle(const std::string &title);
        int getWidth();
        void setWidth(int width);
        int getHeight();
        void setHeight(int height);

        friend std::ostream &operator<<(std::ostream &os, const Display *display);
    };
}

#endif //THEIKOS_SRC_THEIKOS_DISPLAY_H_
