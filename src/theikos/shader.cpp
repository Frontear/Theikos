#include <sstream>
#include "shader.h"

theikos::Shader::Shader(const char *source, GLenum type) {
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (compiled != GL_TRUE) {
        GLchar error[1024];
        glGetShaderInfoLog(shader, 1024, nullptr, error);

        std::stringstream message;
        message << "Failed to compile shader: " << "\n\t" << error;

        throw std::runtime_error(message.str());
    }
}

theikos::Program &theikos::operator<<(theikos::Program &program, const theikos::Shader &shader) {
    program << shader.shader;

    return program;
}
