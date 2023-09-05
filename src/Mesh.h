#include <vector>
#include <glm/glm.hpp>
#include "../VertexObjects/VertexArray.h"



class Mesh{

public:
    Mesh();
    ~Mesh();

    void bind();
    void unbind();
    
    void add_vertex(glm::vec3 vertex);
    void add_index(unsigned int index);

    void clear();

private:
    VertexArray m_vao;
    std::vector<float> m_vertices;
    std::vector<unsigned int> m_indices;
    unsigned int m_index_count = 0;

};