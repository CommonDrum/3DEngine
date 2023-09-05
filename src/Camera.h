#include <glm/glm.hpp>

class Camera{
public:
Camera();
~Camera();

void set_position(glm::vec3 position);
void set_rotation(glm::vec3 rotation);
void set_projection(glm::mat4 projection);
void set_view(glm::mat4 view);
void set_viewport(int width, int height);

private:
glm::vec3 m_position;
glm::vec3 m_rotation;
glm::mat4 m_projection;
glm::mat4 m_view;
int m_width;
int m_height;
};