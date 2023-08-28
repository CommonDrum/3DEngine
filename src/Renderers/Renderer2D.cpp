#include "Renderer2D.h"

Renderer2D::Renderer2D(int width, int height, const char* title) : 
    BaseRenderer(width, height, title),
    m_shader("/home/user/dev/3DEngine/src/Shaders/vertex.glsl", "/home/user/dev/3DEngine/src/Shaders/fragment.glsl"){
}


void Renderer2D::draw_triangle(glm::vec2 pos, glm::vec2 size) {
   
    
    float vertices[] = {
        pos.x, pos.y, 0.0f,
        pos.x + size.x, pos.y, 0.0f,
        pos.x + size.x / 2, pos.y + size.y, 0.0f
    };

    unsigned int indices[] = {
        0, 1, 2
    };




   

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    
}


void Renderer2D::flush() {

  m_shader.Use();



}

void Renderer2D::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}