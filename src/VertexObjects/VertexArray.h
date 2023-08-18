#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexLayout.h"



class VertexArray {

    private:
        unsigned int m_RendererID;
        VertexBufferLayout m_layout;
        VertexBuffer m_vbo;
        IndexBuffer m_ibo;
};