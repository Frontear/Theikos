#include "buffer.h"

theikos::Buffer::Buffer(GLenum buffer_type, size_t size, const GLfloat *vertices, GLenum draw_type) : buffer(), type(buffer_type) {
    glGenBuffers(1, &buffer);
    glBindBuffer(type, buffer);
    glBufferData(type, size, vertices, draw_type);
}

theikos::Buffer::~Buffer() {
    glDeleteBuffers(1, &buffer);
}

void theikos::Buffer::bind() {
    glBindBuffer(type, buffer);
}
