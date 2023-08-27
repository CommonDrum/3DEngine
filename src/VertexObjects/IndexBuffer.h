#include <GL/glew.h>
#include <vector>



class IndexBuffer{
    private:
        unsigned int m_RendererID;
        std::vector<unsigned int> m_Data;
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void Append(const unsigned int* data, unsigned int count);

        void Bind() const;
        void Unbind() const;

        inline unsigned int getCount() const { return m_Data.size(); }
};