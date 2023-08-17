#include "BaseRenderer.h"
#include "Shader.h"
#include "VBO.h"

class Renderer2D : public BaseRenderer {
public:
   Renderer2D(int width, int height, const char* title);
      
    
    virtual ~Renderer2D() {
       glfwTerminate();
    }

    void render() override{
        return;
    }
private:
    //Shader m_shader;
    //VertexBufferObject m_vbo;
};