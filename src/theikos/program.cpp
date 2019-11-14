#include <sstream>
#include "program.h"

theikos::Program::Program() {
    program = glCreateProgram();
}

void theikos::Program::link() {
    glLinkProgram(program);

    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (linked != GL_TRUE) {
        GLchar error[1024];
        glGetProgramInfoLog(program, 1024, nullptr, error);

        std::stringstream message;
        message << "Failed to link program: " << "\n\t" << error;

        throw std::runtime_error(message.str());
    }

    for (auto shader : shaders) {
        glDetachShader(program, shader);
        glDeleteShader(shader);
    }

    shaders.clear();
}

void theikos::Program::use() {
    glUseProgram(program);
}

theikos::Program &theikos::operator<<(theikos::Program &program, const theikos::Shader &shader) {
    program.shaders.push_back(shader.shader);
    glAttachShader(program.program, shader.shader);

    return program;
}
