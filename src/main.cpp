#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <string>
#include <fstream>
#include <sstream>

#include "Shader.h"

GLuint LoadShader(const char* vertexPath, const char* fragmentPath);


int main()
{
    auto logger = spdlog::stdout_color_mt("console");

    

    
    logger->info("GLFW Version: {}", glfwGetVersionString());
    if (!glfwInit())
    {
        logger->error("Failed to initialize GLFW");
        return -1;
    }


    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    logger->info("OpenGL Version: {}", glGetString(GL_VERSION));
    logger->info("GLEW Version: {}", glewGetString(GLEW_VERSION));
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        logger->error("Failed to initialize GLEW");
        return -1;
    }

    GLfloat vertices[] = {
    0.0f,  0.5f, 0.0f,  // Top
   -0.5f, -0.5f, 0.0f,  // Bottom Left
    0.5f, -0.5f, 0.0f   // Bottom Right
    };

    logger->info("Loading Shaders");
    Shader shader("/home/user/dev/3DEngine/src/shaders/vertex.glsl", "/home/user/dev/3DEngine/src/shaders/fragment.glsl");

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);
    

    while (!glfwWindowShouldClose(window))
{
    glClear(GL_COLOR_BUFFER_BIT);

    shader.Use();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();
}




    glfwTerminate();
}
