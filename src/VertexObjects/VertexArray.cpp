#include "VertexArray.h"


VertexArray::VertexArray(const VertexBuffer vb, const IndexBuffer ib){
    m_vboArray.push_back(vb);
    m_iboArray.push_back(ib);
    m_layout = VertexBufferLayout();
    m_layout.push<float>(3);

}

VertexArray::VertexArray(){
    m_layout = VertexBufferLayout();
    m_layout.push<float>(3);
}