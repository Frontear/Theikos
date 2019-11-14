#ifndef THEIKOS_SRC_THEIKOS_SHADER_H_
#define THEIKOS_SRC_THEIKOS_SHADER_H_

#include "internal/opengl.h"
#include "program.h"

namespace theikos {
    class Shader {
    private:
        GLuint shader;

    public:
        Shader(const char *source, GLenum type);

        friend theikos::Program &operator<<(theikos::Program &program, const theikos::Shader &shader);
    };
}

#endif //THEIKOS_SRC_THEIKOS_SHADER_H_
