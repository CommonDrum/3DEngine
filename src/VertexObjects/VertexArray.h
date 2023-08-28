#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"




class VertexArray {
private:
    unsigned int m_RendererID;

public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    // This function associates a VertexBuffer and its layout with the VertexArray
    void AddVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    // This function associates an IndexBuffer with the VertexArray
    void SetIndexBuffer(const IndexBuffer& ib);
};
