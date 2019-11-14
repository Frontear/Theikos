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
        /*
         * even though glGetProgramInfoLog will catch any errors with invalid shader ids,
         * it won't always give a reason, especially if a random number is given
         */
        glDetachShader(program, shader); // todo: better error handling for this
    }

    shaders.clear();
}

void theikos::Program::use() {
    glUseProgram(program);
}

theikos::Program &theikos::operator<<(theikos::Program &program, GLuint shader) {
    program.shaders.push_back(shader);
    glAttachShader(program.program, shader);

    return program;
}
