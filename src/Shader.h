#pragma once
#include <string>

class Shader{
   
    public:
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        ~Shader();	
        void Use();

    private:
        unsigned int shaderProgram;
        std::string readShaderFile(const std::string& filePath);
        void checkCompileErrors(unsigned int shader, const std::string& type);

};