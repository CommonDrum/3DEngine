#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"




class VertexArray {

    private:
        unsigned int m_RendererID;
        VertexBufferLayout m_layout;
        VertexBuffer m_vbo;
        IndexBuffer m_ibo;

    public:

        VertexArray(VertexBuffer vb, IndexBuffer ib);
        //TODO: VertexArray(const VertexBufferLayout& layout);
        ~VertexArray();

        void Bind() const;
        void Unbind() const;

        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
        void AddBuffer(const IndexBuffer& ib);

        void Append(const void * vertexData, const unsigned int * ib, int count);

        inline const VertexBufferLayout& GetLayout() const { return m_layout; }
        inline const VertexBuffer& GetVBO() const { return m_vbo; }
        inline const IndexBuffer& GetIBO() const { return m_ibo; }
};