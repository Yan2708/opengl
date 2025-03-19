#include "VBO.h"

VBO::VBO()
{
    glGenBuffers(1, &id);
}

VBO::~VBO()
{
    unbind();
}

void VBO::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::buffer(float* vertices, int size)
{    
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::unbind()
{
    glDeleteVertexArrays(1, &id);
}
