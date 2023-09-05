#include "Mesh.h"


Mesh::Mesh() {
    m_vao.bind();
}

Mesh::~Mesh() {

}

void Mesh::bind() {
    m_vao.bind();
}

void Mesh::unbind() {
    m_vao.unbind();
}