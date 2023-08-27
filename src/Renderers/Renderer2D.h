#include "BaseRenderer.h"
#include "../Shaders/Shader.h"
#include "../VertexObjects/VertexBuffer.h"
#include "../../vendor/glm/glm/glm.hpp"
#include "../VertexObjects/VertexBufferLayout.h"
#include "../VertexObjects/IndexBuffer.h"

class Renderer2D : public BaseRenderer {
public:
   Renderer2D(int width, int height, const char* title);
      
    
    virtual ~Renderer2D() {
       glfwTerminate();
    }

    void render() override{
        return;
    }

    void draw_triangle(glm::vec2 pos, glm::vec2 size);
    //void draw_triangle(glm::vec2 pos, glm::vec2 size, glm::vec3 color);

    //void draw_square
    //void draw_square(glm::vec2 pos, glm::vec2 size, glm::vec3 color);


    //void draw_circle();

private:
    IndexBuffer * m_ibo;

    //Shader m_shader;
    //VertexBufferObject m_vbo;
};