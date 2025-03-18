#include "VAP.h"
#include <glad/glad.h>

VAP::VAP(int position, int vertexAttributeSize, int type, int normalized, long stride, void* offset):
position(position), vertexAttributeSize(vertexAttributeSize), type(type), normalized(normalized),
stride(stride), offset(offset)
{
}

void VAP::enable()
{
    glVertexAttribPointer(position, vertexAttributeSize, type, normalized, stride, offset);
    glEnableVertexAttribArray(position);
}

void VAP::disable()
{
    glDisableVertexAttribArray(position);
}
