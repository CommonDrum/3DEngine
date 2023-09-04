

#include "BaseRenderer.h"


BaseRenderer::BaseRenderer(int width, int height, const char* title) {

       

        auto logger = spdlog::stdout_color_mt("console");
        //logger->info("OpenGL Version: {}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));


        if (!glfwInit()) {
            //logger->error("Failed to initialize GLFW");
            throw std::runtime_error("Failed to initialize GLFW");
        }
        
         #ifdef __APPLE__
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #endif

        m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!m_window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        

        glfwMakeContextCurrent(m_window);

        //logger->info("OpenGL Version: {}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            logger->error("Failed to initialize GLEW");
            throw std::runtime_error("Failed to initialize GLEW");
        }

        //logger->info("GLEW Version: {}", reinterpret_cast<const char*>(glewGetString(GLEW_VERSION)));
    }


    BaseRenderer::~BaseRenderer() {
    // Cleanup, if necessary
}

