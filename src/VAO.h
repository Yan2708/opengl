#ifndef VAO_H
#define VAO_H
#include "common.h"

class VAO
{
private:
    /* data */
public:
    VAO(/* args */);
    ~VAO();

    unsigned int id;

    void bind();
    void unbind();
};
#endif