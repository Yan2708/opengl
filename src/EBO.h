
#ifndef EBO_H
#define EBO_H
#include "common.h"
class EBO
{
private:
    /* data */
public:
    EBO(/* args */);

    unsigned int id; 

    void bind();
    void buffer(unsigned int* vertices, int size);
};

#endif 


