#include "Camera.h"

Camera::Camera() {
    m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    m_projection = glm::mat4(1.0f);
    m_view = glm::mat4(1.0f);
    m_width = 0;
    m_height = 0;
}

Camera::~Camera() {

}

void Camera::set_position(glm::vec3 position) {
    m_position = position;
}

void Camera::set_rotation(glm::vec3 rotation) {
    m_rotation = rotation;
}

void Camera::set_projection(glm::mat4 projection) {
    m_projection = projection;
}

void Camera::set_view(glm::mat4 view) {
    m_view = view;
}

void Camera::set_viewport(int width, int height) {
    m_width = width;
    m_height = height;
}

glm::vec3 Camera::get_position() {
    return m_position;
}

glm::vec3 Camera::get_rotation() {
    return m_rotation;
}

glm::mat4 Camera::get_projection() {
    return m_projection;
}

glm::mat4 Camera::get_view() {
    return m_view;
}

int Camera::get_width() {
    return m_width;
}

int Camera::get_height() {
    return m_height;
}

