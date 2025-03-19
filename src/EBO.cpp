#include "EBO.h"

EBO::EBO()
{
    glGenBuffers(1, &id);
}
void EBO::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::buffer(unsigned int *vertices, int size)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

