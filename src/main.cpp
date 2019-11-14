#include <iostream>
#include "theikos/display.h"
#include "theikos/shader.h"
#include "theikos/program.h"

int main() {
    auto display = theikos::Display("Theikos", 640, 480);
    std::cout << display;

    // -- RETAINED MODE
    GLuint array;
    glGenVertexArrays(1, &array);
    glBindVertexArray(array);

    const GLfloat vert[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

    const char *v_shader =
        R"glsl(
        #version 330 core

        layout(location = 0) in vec3 coord;

        void main() {
            gl_Position.xyz = coord;
            gl_Position.w = 1.0;
        }
        )glsl";

    const char *f_shader =
        R"glsl(
        #version 330 core

        out vec3 color;

        void main() {
            color = vec3(0.5, 0.5, 1.0);
        }
        )glsl";

    auto program = theikos::Program();
    {
        auto s_vertex = theikos::Shader(v_shader, GL_VERTEX_SHADER);
        auto s_fragment = theikos::Shader(f_shader, GL_FRAGMENT_SHADER);

        program << s_vertex << s_fragment;
        program.link();
    }
    // -- RETAINED MODE

    do {
        glClear(GL_COLOR_BUFFER_BIT);

        // -- RETAINED MODE
        program.use();

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);
        // -- RETAINED MODE

        display.tick();
    }
    while (display.isAlive());

    return 0;
}