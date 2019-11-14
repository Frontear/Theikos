#ifndef THEIKOS_SRC_THEIKOS_PROGRAM_H_
#define THEIKOS_SRC_THEIKOS_PROGRAM_H_

#include "internal/opengl.h"
#include "shader.h"
#include <vector>
#include <ostream>

namespace theikos {
    class Program {
    private:
        GLuint program;
        std::vector<GLuint> shaders;

    public:
        Program();

        void link();
        void use();

        friend theikos::Program &operator<<(theikos::Program &program, const theikos::Shader &shader);
    };
}

#endif //THEIKOS_SRC_THEIKOS_PROGRAM_H_
