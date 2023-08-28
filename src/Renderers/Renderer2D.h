#include "BaseRenderer.h"
#include "../Shaders/Shader.h"
#include "../../vendor/glm/glm/glm.hpp"
#include "../VertexObjects/VertexArray.h"

class Renderer2D : public BaseRenderer {
public:
   Renderer2D(int width, int height, const char* title);
      
    
    virtual ~Renderer2D() {
       glfwTerminate();
    }

   void flush() override;
   void clear() const override;

    void draw_triangle(glm::vec2 pos, glm::vec2 size);
    //void draw_triangle(glm::vec2 pos, glm::vec2 size, glm::vec3 color);

    //void draw_square
    //void draw_square(glm::vec2 pos, glm::vec2 size, glm::vec3 color);


    //void draw_circle();

private:
 
    Shader m_shader;
    VertexArray m_vao;
    std::vector<float> m_vertices;
    std::vector<unsigned int> m_indices;
    unsigned int m_index_count = 0;
};