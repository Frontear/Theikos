#ifndef THEIKOS_SRC_THEIKOS_BUFFER_H_
#define THEIKOS_SRC_THEIKOS_BUFFER_H_

#include <initializer_list>
#include "internal/opengl.h"

namespace theikos {
    class Buffer {
    private:
        GLuint buffer;
        GLuint type;

    public:
        Buffer(GLenum buffer_type, size_t size, const GLfloat* vertices, GLenum draw_type); // todo: implicitly determine array size using size_t
        virtual ~Buffer();

        void bind();
    };
}
#endif //THEIKOS_SRC_THEIKOS_BUFFER_H_
