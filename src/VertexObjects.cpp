#include "VertexObjects.h"


#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


unsigned int VertexBufferElement::GetSizeOfType(unsigned int type){
   {
        switch(type)
        {
            case GL_FLOAT: return sizeof(GLfloat);
            case GL_UNSIGNED_INT: return sizeof(GLuint);
            case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
            
            default: assert(false); return 0;
        }
    }
}


VertexArrayObject::VertexArrayObject(){
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
}

VertexArrayObject::~VertexArrayObject(){
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArrayObject::Bind(){
    glBindVertexArray(m_RendererID);
}

void VertexArrayObject::Unbind(){
    glBindVertexArray(0);
}

void VertexArrayObject::AddBuffer(VertexBufferObject& vbo, VertexBufferLayout& layout){
    Bind();
    vbo.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for(unsigned int i = 0; i < elements.size(); i++){
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}


template<>
void VertexBufferLayout::Push<float>(unsigned int count){
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template<>
void VertexBufferLayout::Push<unsigned int>(unsigned int count){
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::Push<unsigned char>(unsigned int count){
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}

