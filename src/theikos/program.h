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

        void link();
        void use(); // todo: fail if link hasn't been called at least once

        friend theikos::Program &operator<<(theikos::Program &program,
                                            GLuint shader); // todo: prevent this from allowing any random number
    };
}

#endif //THEIKOS_SRC_THEIKOS_PROGRAM_H_
