#version 330 core            // This defines the version of GLSL we're using. 330 corresponds to OpenGL 3.3.

layout(location = 0) in vec2 position;  // This is our input vertex position. We assume it's a 2D position for simplicity.

void main() {
    gl_Position = vec4(position, 0.0f, 1.0f); // We convert our 2D position to a 4D vector. The new Z value is 0.0 and W is 1.0.
}
