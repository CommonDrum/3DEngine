#include "BaseRenderer.h"
#include "../Shaders/Shader.h"
#include "../VertexObjects/VBO.h"

class Renderer2D : public BaseRenderer {
public:
   Renderer2D(int width, int height, const char* title);
      
    
    virtual ~Renderer2D() {
       glfwTerminate();
    }

    void render() override{
        return;
    }

    //void draw_triangle();

    //void draw_square();

    //void draw_circle();

private:
    //Shader m_shader;
    //VertexBufferObject m_vbo;
};