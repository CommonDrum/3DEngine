#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <GL/glew.h>
 
 
 /*
    Shader class needs:
        - A constructor accepting paths to the vertex and fragment shader files. DONE
        - A method to activate the shader (Use).
        - Private methods to check shader and program compilation/linking errors.
        - A private variable to store the OpenGL ID of the compiled shader program.
        - A destructor to clean up resources.
        
    */

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath){

    std::string vertexCode = readShaderFile(vertexPath);
    std::string fragmentCode = readShaderFile(fragmentPath);
    
    if(vertexCode.empty() || fragmentCode.empty()){
        spdlog::error("Failed to read shader files.");
        return;
    }

                /* Compile shaders */

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Attach shader source code to shaders

    const char* vertexShaderSource = vertexCode.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

    const char* fragmentShaderSource = fragmentCode.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);


    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

// Check for errors TODO: MOVE INTO FUNCTION LATER

    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    GLchar infoLog[512];
    if (!success){
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            spdlog::error("Vertex shader compilation failed: {}", infoLog);
        }
     
        

                /* Link shaders */

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for errors TODO: MOVE INTO FUNCTION LATER
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            spdlog::error("Shader program linking failed: {}", infoLog);
        }

    // Clean up shaders after linking
    glDetachShader(shaderProgram, vertexShader);
    glDetachShader(shaderProgram, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


Shader::~Shader(){
        
    
    }

void Shader::Use(){
        glUseProgram(shaderProgram);
    }

std::string Shader::readShaderFile(const std::string& filePath){

    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()){
        spdlog::error("Could not read file {}.", filePath);
        return "";
    }

    std::stringstream sstr;
    sstr << fileStream.rdbuf();
    content = sstr.str();

    fileStream.close();
    return content;
}