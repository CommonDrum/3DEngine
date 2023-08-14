#include <GL/glew.h>
#include <cassert>
#include <vector>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
    static unsigned int GetSizeOfType(unsigned int type);
};



class VertexBufferObject{
    public:
        VertexBufferObject(const void* data, unsigned int size, unsigned int usage);
        ~VertexBufferObject();
        void Bind();
        void Unbind();
    private:
        unsigned int m_RendererID;
};


class VertexBufferLayout{
    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;
        
    public:
        VertexBufferLayout(){m_Stride = 0;};
        ~VertexBufferLayout();

        template<typename T>
    void Push(unsigned int count){

    }

    inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
    inline unsigned int GetStride() const { return m_Stride; }
    
        
};


class VertexArrayObject{
    public:
        VertexArrayObject();
        ~VertexArrayObject();
        void Bind();
        void Unbind();
        void AddBuffer(VertexBufferObject& vbo, VertexBufferLayout& layout);
    private:
        unsigned int m_RendererID;
};
