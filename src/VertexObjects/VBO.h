class VertexBufferObject{
    public:
        VertexBufferObject(const void* data, unsigned int size, unsigned int usage);
        ~VertexBufferObject();
        void Bind();
        void Unbind();
    private:
        unsigned int m_RendererID;
};