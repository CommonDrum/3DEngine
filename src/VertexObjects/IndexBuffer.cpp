#include "IndexBuffer.h"



IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) {
    for (int i = 0; i < count; i++) {
        m_Data.push_back(data[i]);
    }

    glGenBuffers(1, &m_RendererID);

}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_RendererID);
}

void IndexBuffer::Append(const unsigned int* data, unsigned int count) {
    for (int i = 0; i < count; i++) {
        m_Data.push_back(data[i] + m_Data.size());
    }
}

void IndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Data.size() * sizeof(unsigned int), &m_Data[0], GL_STATIC_DRAW);
}

void IndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}