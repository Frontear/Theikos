#ifndef THEIKOS_SRC_THEIKOS_SHADER_H_
#define THEIKOS_SRC_THEIKOS_SHADER_H_

#include "internal/opengl.h"

namespace theikos {
    class Shader {
    public: // todo: turn into private
        GLuint shader;

    public:
        Shader(const char *source, GLenum type);
    };
}

#endif //THEIKOS_SRC_THEIKOS_SHADER_H_
