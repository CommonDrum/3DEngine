#include "Camera.h"

Camera::Camera() {
    m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    m_projection = glm::mat4(1.0f);
    m_view = glm::mat4(1.0f);
    m_width = 0;
    m_height = 0;
}