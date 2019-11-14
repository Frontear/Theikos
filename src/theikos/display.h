#ifndef THEIKOS_SRC_THEIKOS_DISPLAY_H_
#define THEIKOS_SRC_THEIKOS_DISPLAY_H_

#include <string>
#include "internal/opengl.h"
#include <ostream>

namespace theikos {
    class Display {
    private:
        std::string title;
        GLFWwindow *ptr;

        static bool setup;

    public:
        Display(std::string window_title, int window_width, int window_height); // todo: reduce throw repetition
        virtual ~Display();

        bool isAlive();
        void tick();

        std::string getTitle();
        void setTitle(std::string new_title);

        [[nodiscard]]
        int getWidth() const;
        void setWidth(int new_width);

        [[nodiscard]]
        int getHeight() const;
        void setHeight(int new_height);

        friend std::ostream &operator<<(std::ostream &os, const Display &display);
    };
}

#endif //THEIKOS_SRC_THEIKOS_DISPLAY_H_
