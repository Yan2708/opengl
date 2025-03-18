#include "VAO.h"
#include <glad/glad.h>

VAO::VAO()
{
    glGenVertexArrays(1, &id);
}

VAO::~VAO()
{
    unbind();
}

void VAO::bind()
{
    glBindVertexArray(id);
}

void VAO::unbind()
{
    glDeleteBuffers(1, &id);
}
