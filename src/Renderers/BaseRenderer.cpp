

#include "BaseRenderer.h"


BaseRenderer::BaseRenderer(int width, int height, const char* title) {
        auto logger = spdlog::stdout_color_mt("console");
        logger->info("GLFW Version: {}", glfwGetVersionString());

        if (!glfwInit()) {
            logger->error("Failed to initialize GLFW");
            throw std::runtime_error("Failed to initialize GLFW");
        }

        m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!m_window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(m_window);

        logger->info("OpenGL Version: {}", glGetString(GL_VERSION));
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            logger->error("Failed to initialize GLEW");
            throw std::runtime_error("Failed to initialize GLEW");
        }

        logger->info("GLEW Version: {}", glewGetString(GLEW_VERSION));
    }


    BaseRenderer::~BaseRenderer() {
    // Cleanup, if necessary
}

