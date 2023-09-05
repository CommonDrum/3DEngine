#include "Renderer2D.h"



Renderer2D::Renderer2D(int width, int height, const char* title) : 
    BaseRenderer(width, height, title),
    //TODO: make shader path relative
    m_shader("/Users/commondrum/Documents/GitHub/Renderer/src/Shaders/vertex.glsl", "/Users/commondrum/Documents/GitHub/Renderer/src/Shaders/fragment.glsl"){
}


void Renderer2D::draw_triangle(glm::vec2 pos, glm::vec2 size) {
   
    
    m_vertices.insert( m_vertices.end(), {
        pos.x, pos.y, 0.0f,
        pos.x + size.x, pos.y, 0.0f,
        pos.x + size.x / 2, pos.y + size.y, 0.0f
    });

    m_indices.insert(m_indices.end(),{0+m_index_count, 1+m_index_count, 2+m_index_count});

    m_index_count += 3;
    
}

void Renderer2D::draw_square(glm::vec2 pos, glm::vec2 size){

    //TODO: figure out maths to make size acurate
    m_vertices.insert( m_vertices.end(), {
        pos.x + size.x/2, pos.y + size.y/2, 0.0f,
        pos.x + size.x/2, pos.y - size.y/2, 0.0f,
        pos.x - size.x/2, pos.y - size.y/2, 0.0f,
        pos.x - size.x/2, pos.y + size.y/2, 0.0f
    });

    m_indices.insert(m_indices.end(),{
        0+m_index_count, 1+m_index_count, 3+m_index_count,
        1+m_index_count, 2+m_index_count, 3+m_index_count
        });

    

    m_index_count += 6;
}


void Renderer2D::flush() {

  m_shader.Use();
    VertexBuffer vbo(m_vertices.data(), m_vertices.size() * sizeof(float), GL_STATIC_DRAW);
    IndexBuffer ibo(m_indices.data(), m_indices.size());

    //create layout
    VertexBufferLayout layout;
    layout.push<float>(3);

    m_vao.AddVertexBuffer(vbo, layout);
    m_vao.SetIndexBuffer(ibo);

    m_vao.Bind();
    glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr);

    m_vertices.clear();
    m_indices.clear();
    m_index_count = 0;
}

void Renderer2D::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}