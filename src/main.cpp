#include "Renderers/Renderer2D.h"


int main()
{
    Renderer2D renderer(640, 480, "Renderer2D");

    
    


    while (!glfwWindowShouldClose(renderer.m_window))
{
    renderer.clear();
    
    renderer.draw_triangle(glm::vec2(0.0f, 0.0f), glm::vec2(0.5f, 0.5f));
    renderer.draw_triangle(glm::vec2(0.5f, 0.5f), glm::vec2(0.5f, 0.5f));

    renderer.flush();

    glfwSwapBuffers(renderer.m_window);

    
    glfwPollEvents();
}




}
