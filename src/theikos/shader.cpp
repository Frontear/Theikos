#include <sstream>
#include "shader.h"

theikos::Shader::Shader(const char *source, GLenum type) {
    if (source == nullptr) {
        throw std::runtime_error("Shader source cannot be null");
    }

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

theikos::Shader::~Shader() {
    glDeleteShader(shader);

    if (glIsShader(shader) == GL_TRUE) {
        throw std::runtime_error("Failed to delete shader");
    }
}
