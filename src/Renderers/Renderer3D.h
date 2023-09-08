#include "BaseRenderer.h"

class Renderer3D : public BaseRenderer {

Renderer3D(int width, int height, const char* title);
~Renderer3D();

void render();

void flush() override;
void clear() override;



};