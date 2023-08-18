class VertexBuffer{
    public:
        VertexBuffer(const void* data, unsigned int size, unsigned int usage);
        ~VertexBuffer();
        void Bind();
        void Unbind();
    private:
        unsigned int m_RendererID;
};