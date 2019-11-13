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
        int width, height;
        GLFWwindow* ptr;

        static bool setup;

    public:
        Display(std::string window_title, int window_width, int window_height);
        virtual ~Display();

        bool isAlive();
        void tick();

        std::string getTitle();
        void setTitle(std::string new_title);

        int getWidth();
        void setWidth(int new_width);

        int getHeight();
        void setHeight(int new_height);

        friend std::ostream &operator<<(std::ostream &os, const Display &display);
    };
}

#endif //THEIKOS_SRC_THEIKOS_DISPLAY_H_
