#ifndef THEIKOS_SRC_THEIKOS_PROGRAM_H_
#define THEIKOS_SRC_THEIKOS_PROGRAM_H_

#include "internal/opengl.h"
#include <vector>
#include <ostream>

namespace theikos {
    class Program {
    private:
        bool setup;
        GLuint program;
        std::vector<GLuint> shaders;

    public:
        Program();
        virtual ~Program();

        void link();
        void use();

        friend theikos::Program &operator<<(theikos::Program &program, GLuint shader);
    };
}

#endif //THEIKOS_SRC_THEIKOS_PROGRAM_H_
