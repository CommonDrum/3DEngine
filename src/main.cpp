#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <string>
#include <fstream>
#include <sstream>

#include "Renderers/Renderer2D.h"

GLuint LoadShader(const char* vertexPath, const char* fragmentPath);


int main()
{
    Renderer2D renderer(640, 480, "Renderer2D");
    GLfloat vertices[] = {
    0.0f,  0.5f, 0.0f,  // Top
   -0.5f, -0.5f, 0.0f,  // Bottom Left
    0.5f, -0.5f, 0.0f   // Bottom Right
    };

    Shader shader("/home/user/dev/3DEngine/src/Shaders/vertex.glsl", "/home/user/dev/3DEngine/src/Shaders/fragment.glsl");


    VertexBufferObject vbo(vertices, sizeof(vertices), GL_STATIC_DRAW);


    while (!glfwWindowShouldClose(renderer.m_window))
{
    glClear(GL_COLOR_BUFFER_BIT);

    shader.Use();
    vbo.Bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    glfwSwapBuffers(renderer.m_window);
    glfwPollEvents();
}




}
