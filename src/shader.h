#ifndef SHADER_H
#define SHADER_H
#include "common.h"
class Shader
{
public:
    Shader(std::string path, int type);
    ~Shader();
    unsigned int id;
private:
    static std::string readFile(std::string path);
};

#endif