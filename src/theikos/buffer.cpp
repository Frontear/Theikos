#include <stdexcept>
#include "buffer.h"

theikos::Buffer::Buffer(GLenum buffer_type, size_t size, const GLfloat *vertices, GLenum draw_type)
    : buffer(), type(buffer_type) {
    glGenBuffers(1, &buffer);
    glBindBuffer(type, buffer);
    glBufferData(type, size, vertices, draw_type);

    GLint loaded_size;
    glGetBufferParameteriv(type, GL_BUFFER_SIZE, &loaded_size);
    if (size != loaded_size) {
        throw std::runtime_error("Failed to load buffer");
    }
}

theikos::Buffer::~Buffer() {
    glDeleteBuffers(1, &buffer);

    if (glIsBuffer(buffer) == GL_TRUE) {
        throw std::runtime_error("Failed to delete buffer");
    }
}

void theikos::Buffer::bind() {
    glBindBuffer(type, buffer);
}
