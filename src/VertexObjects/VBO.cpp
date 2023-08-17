#include "VBO.h"
#include <GL/glew.h>


VertexBufferObject::VertexBufferObject(const void* data, unsigned int size, unsigned int usage){ 
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

VertexBufferObject::~VertexBufferObject(){
    glDeleteBuffers(1, &m_RendererID);
}

void VertexBufferObject::Bind(){
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBufferObject::Unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}